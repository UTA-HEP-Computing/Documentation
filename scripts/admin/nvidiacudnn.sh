#!/bin/bash

#Run as root. make sure you cd to cudnn directory first.
#If cudnn has not been downloaded yet, refer to download link in admin guide


cp -P include/cudnn.h /usr/include
cp -P lib64/libcudnn* /usr/lib/x86_64-linux-gnu/
chmod a+r /usr/lib/x86_64-linux-gnu/libcudnn*