#!/bin/bash

# Navigate to the directory containing your local Git repository
# cd "$(dirname "$0")"
cd ..

# Read user input
read -p "what change are we making today: " modification


branch='main'

git init

# Add all changes to the Git staging are
git add .

#check status of files to be committed
git status

# Commit the changes with a descriptive message
git commit -m "$modification"

git branch -M $branch

git remote add origin https://github.com/kuriofoolio/compiler-assignment.git

# Push the changes to your GitHub repository
git push -u origin $branch
