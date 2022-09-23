## Install catkin_create_qt_pkg
```
sudo apt-get install ros-melodic-qt-create
catkin_create_qt_pkg myQtApp roscpp rviz std_msgs
```

## Install Qt4
```
sudo apt update
sudo apt install qt4-dev-tools
```

## Checkout on Ubuntu
```
mkdir -p ~/rviz_plugin/src/
cd ~/rviz_plugin/src

git init
git config core.sparsecheckout true
echo rviz_telop_commander/ >> .git/info/sparse-checkout
git remote add -f origin http://192.168.3.82:3000/csu/sample.git
git pull origin master
```
[在rviz中添加插件](https://blog.csdn.net/weixin_40047925/article/details/80880945)