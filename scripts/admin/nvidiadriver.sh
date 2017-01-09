#!/bin/bash

#this servers as a guide:
# recommended to run the lines individually.
# Also, use 'apt-cache search nvidia' to check for more recent drivers.

apt-get update

sudo add-apt-repository ppa:graphics-drivers/ppa
sudo apt update

apt-get install nvidia-375
