#!/usr/bin/env python3

# imports
import os
import subprocess
import sys

# Global Variable
file = "apps"

def quit():
    sys.exit("Thank you for using my script")

def help():
    print("Here is a list of options...")
    print("\tadd\n\tlist\n\thelp\n\tcheck\n\tinstall\n\tremove\n\tquit")
    main()
    
def check_app_list():
    open_it = open(file, 'r')
    for app in open_it:
        print(app.strip())
    open_it.close()
    main()
    
def append_app_list():
    current_state = True
    while(current_state):
        new_app = input("What program would you like add? (type quit to quit) ")
        if (new_app == "quit"):
            current_state = False
        else:
            open_it = open(file, 'a')
            open_it.write(new_app + '\n')
            open_it.close()
    print("Printing new list...")
    check_app_list()
    main()
    
def remove_app_from_list():
    print("Here is the list of apps")
    open_it = open(file, 'r')
    for app in open_it:
        print(app.strip())
    open_it.close()
    print("Please enter the app you would like to remove") 
    app_to_delete = input(">: ")
    with open(file,'r+') as f:
        current_apps = f.readlines()
        f.seek(0)
        for app in current_apps:
            if (app.strip("\n") != app_to_delete):
                    f.write(app)
        f.truncate()
        f.close()
    main()
    
def check_installed():
    print("Enter app to see if installed")
    app = input("> ")
    check_app = subprocess.run(["which", app])
    if (check_app.returncode == 1):
        print(app + " is not installed")
        #ask = input("Would you like to install it? (y/n) " )
    else:
        print(app + " is installed")
    main()
        
def install_apps():
    read_file = open(file, 'r')
    for app in read_file:
        app = app.strip()
        subprocess.run(["sudo", "apt", "install", app, "-y"])
    read_file.close()
    main()
    
def main():
    decide = input("Choice: ")
    if (decide == "help"):
        help()
    elif (decide == "check"):
        check_installed()
    elif (decide == "list"):
        check_app_list()
    elif (decide == "install"):
        install_apps()
    elif (decide == "add"):
        append_app_list()
    elif (decide == "remove"):
        remove_app_from_list()
    elif (decide == "quit"):
        quit()
    else:
        main()
main()
