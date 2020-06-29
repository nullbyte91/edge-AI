#include <VX/vx.h>
#include <VX/vxu.h>
#include <NVX/nvx_opencv_interop.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

#define VX_THROW_EXCEPTION(msg)		\
	do { \
		std::ostringstream ostr_; \
		ostr_ << msg; \
		throw std::runtime_error(ostr_.str()); \
	} while(0)

#define VX_SAFE_CALL(vxOp) \
	do \
	{ \
		vx_status status = (vxOp); \
		if (status != VX_SUCCESS) \
		{ \
			VX_THROW_EXCEPTION(#vxOp << " failure [status = " << status << "]" << " in file " << __FILE__ << " line " << __LINE__); \
		} \
	} while (0)

#define VX_ASSERT(cond) \
	do \
	{ \
		if (!(cond)) \
		{ \
			VX_THROW_EXCEPTION(#cond << " failure in file " << __FILE__ << " line " << __LINE__); \
		} \
	} while (0)

#define VX_CHECK_REFERENCE(ref) \
	VX_ASSERT(ref != 0 && vxGetStatus((vx_reference)ref) == VX_SUCCESS)
    
int main(int argc, char* argv[])
{
	/* Load an Image */
	cv::Mat src = cv::imread("../data/lena.jpg", cv::IMREAD_GRAYSCALE);
	if(src.empty())
	{
		std::cerr << "Error: Could not load image file." << std::endl;
		return -1;
	}

	cv::Mat dst(src.size(), src.type(), cv::Scalar(0));

	/* create context */
	vx_context context = vxCreateContext();
	VX_CHECK_REFERENCE(context);

	/* Convert from Mat to vx_image */
	vx_image v_src = nvx_cv::createVXImageFromCVMat(context, src);
	vx_image v_dst = nvx_cv::createVXImageFromCVMat(context, dst);
	VX_CHECK_REFERENCE(v_src);
	VX_CHECK_REFERENCE(v_dst);

	/* launch OpenVX API*/
	VX_SAFE_CALL(vxuBox3x3(context, v_src, v_dst));

	/* Convert from vx_image to Mat */
	nvx_cv::VXImageToCVMatMapper mapper(v_dst, 0, NULL, VX_READ_AND_WRITE, VX_MEMORY_TYPE_HOST);
	cv::Mat result = mapper.getMat();

	cv::imshow("cv2-vxImage-cv2", result);
	cv::waitKey(0);

	/* release resource */
	VX_SAFE_CALL(vxReleaseImage(&v_src));
	VX_SAFE_CALL(vxReleaseImage(&v_dst));
	VX_SAFE_CALL(vxReleaseContext(&context));

	return 0;
}
