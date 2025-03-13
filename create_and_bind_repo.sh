#!/bin/bash

# 设置变量
LOCAL_DIR="d:\Users\tomfa\Documents\code\cpp-school"
REMOTE_URL="https://github.com/mingqian-233/CPP-school.git"

# 创建本地 Git 仓库
cd $LOCAL_DIR
git init

# 添加所有文件并提交
git add .
git commit -m "Initial commit"

# 绑定本地仓库与远程仓库
git remote add origin $REMOTE_URL

# 推送本地代码到远程仓库
git push -u origin main
