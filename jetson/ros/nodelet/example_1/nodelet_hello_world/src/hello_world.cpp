// Plugin Header files
#include <nodelet/nodelet.h>

//  ROS Header files
#include <ros/ros.h>

// string message
#include <std_msgs/String.h>
#include <stdio.h>

namespace nodelet_hello_world
{
class Hello : public nodelet::Nodelet
{
    private:
        virtual void onInit()
        {
            NODELET_DEBUG("Initialized the Hello Nodelet");    
            // ROS Private handler
            ros::NodeHandle & private_nh_ = getPrivateNodeHandle();
            
            pub_ = private_nh_.advertise<std_msgs::String>("msg_out",5);
            
            sub_ = private_nh_.subscribe("msg_in",5, &Hello::callback, this);
        }

        void callback(const std_msgs::StringConstPtr input)
        {
            std_msgs::String output_;
            output_.data = input->data;
            NODELET_DEBUG("Message data = %s",output_.data.c_str());
            ROS_INFO("Message data = %s",output_.data.c_str());
            pub_.publish(output_);
        }
        
    // Publisher node
    ros::Publisher pub;
    
    // Subscriber node
    ros::Subscriber sub;
};
}
#include <pluginlib/class_list_macros.h>
PLUGINLIB_EXPORT_CLASS(nodelet_hello_world::Hello, nodelet::Nodelet)