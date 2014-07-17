#
# Cookbook Name:: buffer-overflow
# Recipe:: default
#
# Copyright 2014, MITRE
#
# All rights reserved - Do Not Redistribute
#
cookbook_file "listener" do
  path "/usr/bin/listener"
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