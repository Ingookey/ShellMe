#!/bin/bash
# using select in the menu

function diskspace {
	clear 
	df -k
}

function whoseon {
	clear
	who
}

function menusage {
	clear
	cat /proc/meminfo
}

PS3="Enter option:"
select option in "Display disk space" "Display logged on users" "Display memory usage" "Exit program"
do
	case $option in
	"Exit program")
		break;;
	"Display disk space")
		diskspace;;
	"Display logged on users")
		whoseon;;
	"Display memory usage")
		menusage;;
	*)
		clear
        dialog --title text --msgbox "This is a test" 10 20
		echo "Sorry, wrong selection";;
	esac
done
clear