#
# Cookbook Name:: buffer-overflow
# Recipe:: default
#
# Copyright 2014, MITRE
#
# All rights reserved - Do Not Redistribute
#
package "python-twisted" do
  action :install
end

cookbook_file "listener.py" do
  path "/usr/bin/listener.py"
  action :create
  mode 0755
end

cookbook_file "/etc/init.d/listener" do
  source "listener_init_d"
  mode 0755
end

service "listener" do
  action [:start, :enable]
end