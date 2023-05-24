#! /usr/bin/bash

function user_permission() {
	echo "Changing USER permission..."
	if [[ "$1" == "1" ]]; then
		chmod u+r $2
	elif [[ "$1" == "2" ]]; then
		chmod u+w $2
	elif [[ "$1" == "3" ]]; then
		chmod u+x $2
	fi
}

function group_permission() {
	echo "Changing GROUP permission..."
	if [[ "$1" == "1" ]]; then
		chmod g+r $2
	elif [[ "$1" == "2" ]]; then
		chmod g+w $2
	elif [[ "$1" == "3" ]]; then
		chmod g+x $2
	fi
}

function other_permission() {
	echo "Changing OTHER permission..."
	if [[ "$1" == "1" ]]; then
		chmod o+r $2
	elif [[ "$1" == "2" ]]; then
		chmod o+w $2
	elif [[ "$1" == "3" ]]; then
		chmod o+x $2
	fi
}

function user_permission_remove() {
	echo "Changing USER permission..."
	if [[ "$1" == "4" ]]; then
		chmod u-r $2
	elif [[ "$1" == "5" ]]; then
		chmod u-w $2
	elif [[ "$1" == "6" ]]; then
		chmod u-x $2
	fi
}

function group_permission_remove() {
	echo "Changing GROUP permission..."
	if [[ "$1" == "4" ]]; then
		chmod g-r $2
	elif [[ "$1" == "5" ]]; then
		chmod g-w $2
	elif [[ "$1" == "6" ]]; then
		chmod g-x $2
	fi
}

function other_permission_remove() {
	echo "Changing OTHER permission..."
	if [[ "$1" == "4" ]]; then
		chmod o-r $2
	elif [[ "$1" == "5" ]]; then
		chmod o-w $2
	elif [[ "$1" == "6" ]]; then
		chmod o-x $2
	fi
}

function continue_editing() {
    read -p "Enter file name as listed above: " FILENAME
		sleep 1
		echo "What permission do you want to change:"
		echo "1. Add Read"
		echo "2. Add Write"
		echo "3. Add Execute"
		echo "4. Remove Read"
		echo "5. Remove Write"
		echo "6. Remove Execute"
		read -p "Enter choice(1/2/3/4/5/6): " PERMCHOICE
		sleep 1
		echo "####################"
		echo "For which Entity:"
		echo "1. User = u"
		echo "2. Group = g"
		echo "3. Other = o"
		read -p "Enter choice(u/g/o): " ENTITYCHOICE
		sleep 1
		if [[ "$ENTITYCHOICE" == "u" || "$ENTITYCHOICE" == "U" ]]; then
			user_permission "$PERMCHOICE" "$FILENAME"
			sleep 2
			echo "$(ls -1 -l)"
			sleep 1
			read -p "Do you want to edit another file? (Y/N): " CONTINUEDECISION
			if [[ "$CONTINUEDECISION" == "Y" || "$CONTINUEDECISION" == "y" ]]; then
				sleep 1
				continue_editing
			else
				echo "###--Exiting Script--###"
			fi
		elif [[ "$ENTITYCHOICE" == "g" || "$ENTITYCHOICE" == "G" ]]; then
			group_permission "$PERMCHOICE" "$FILENAME"
			sleep 2
			echo "$(ls -1 -l)"
			sleep 1
			read -p "Do you want to edit another file? (Y/N): " CONTINUEDECISION
			if [[ "$CONTINUEDECISION" == "Y" || "$CONTINUEDECISION" == "y" ]]; then
				sleep 1
				continue_editing
			else
				echo "###--Exiting Script--###"
			fi
		elif [[ "$ENTITYCHOICE" == "o" || "$ENTITYCHOICE" == "O" ]]; then
			other_permission "$PERMCHOICE" "$FILENAME"
			sleep 2
			echo "$(ls -1 -l)"
			sleep 1
			read -p "Do you want to edit another file? (Y/N): " CONTINUEDECISION
			if [[ "$CONTINUEDECISION" == "Y" || "$CONTINUEDECISION" == "y" ]]; then
				sleep 1
				continue_editing
			else
				echo "###--Exiting Script--###"
			fi
		else
			echo "Kindly choose a valid Entity..."
			sleep 1
			read -p "Do you want to edit another file? (Y/N): " CONTINUEDECISION
			if [[ "$CONTINUEDECISION" == "Y" || "$CONTINUEDECISION" == "y" ]]; then
				sleep 1
				continue_editing
			else
				echo "###--Exiting Script--###"
			fi
		fi
}

cat << "EOF"
______           _                     _                                  _   
| ___ \         | |                   (_)                                | |  
| |_/ / __ _ ___| |__     __ _ ___ ___ _  __ _ _ __  _ __ ___   ___ _ __ | |_ 
| ___ \/ _` / __| '_ \   / _` / __/ __| |/ _` | '_ \| '_ ` _ \ / _ \ '_ \| __|
| |_/ / (_| \__ \ | | | | (_| \__ \__ \ | (_| | | | | | | | | |  __/ | | | |_ 
\____/ \__,_|___/_| |_|  \__,_|___/___/_|\__, |_| |_|_| |_| |_|\___|_| |_|\__|
                                          __/ |                               

EOF

echo "####################"
echo ""
echo "File Permission Editor"
echo ""
echo "####################"
echo ""

echo "$(ls -1 -l)"
echo ""

read -p "Do you want to edit file permissions? (Y/N)" DECISION
case $DECISION in
	[yY] | [yY][eE][sS] )
		echo "$(ls -1)"
		read -p "Enter file name as listed above: " FILENAME
		sleep 1
		echo "What permission do you want to change:"
		echo "1. Add Read"
		echo "2. Add Write"
		echo "3. Add Execute"
		echo "4. Remove Read"
		echo "5. Remove Write"
		echo "6. Remove Execute"
		read -p "Enter choice(1/2/3/4/5/6): " PERMCHOICE
		sleep 1
		echo "####################"
		echo "For which Entity:"
		echo "1. User = u"
		echo "2. Group = g"
		echo "3. Other = o"
		read -p "Enter choice(u/g/o): " ENTITYCHOICE
		sleep 1
		if [[ "$ENTITYCHOICE" == "u" || "$ENTITYCHOICE" == "U" ]]; then
			user_permission "$PERMCHOICE" "$FILENAME"
			sleep 2
			echo "$(ls -1 -l)"
			sleep 1
			read -p "Do you want to edit another file? (Y/N): " CONTINUEDECISION
			if [[ "$CONTINUEDECISION" == "Y" || "$CONTINUEDECISION" == "y" ]]; then
				sleep 1
				continue_editing
			else
				echo ""
				echo "###--Exiting Script--###"
			fi
		elif [[ "$ENTITYCHOICE" == "g" || "$ENTITYCHOICE" == "G" ]]; then
			group_permission "$PERMCHOICE" "$FILENAME"
			sleep 2
			echo "$(ls -1 -l)"
			sleep 1
			read -p "Do you want to edit another file? (Y/N): " CONTINUEDECISION
			if [[ "$CONTINUEDECISION" == "Y" || "$CONTINUEDECISION" == "y" ]]; then
				sleep 1
				continue_editing
			else
				echo ""
				echo "###--Exiting Script--###"
			fi
		elif [[ "$ENTITYCHOICE" == "o" || "$ENTITYCHOICE" == "O" ]]; then
			other_permission "$PERMCHOICE" "$FILENAME"
			sleep 2
			echo "$(ls -1 -l)"
			sleep 1
			read -p "Do you want to edit another file? (Y/N): " CONTINUEDECISION
			if [[ "$CONTINUEDECISION" == "Y" || "$CONTINUEDECISION" == "y" ]]; then
				sleep 1
				continue_editing
			else
				echo ""
				echo "###--Exiting Script--###"
			fi
		else
			echo "Kindly choose a valid Entity..."
			sleep 1
			read -p "Do you want to edit another file? (Y/N): " CONTINUEDECISION
			if [[ "$CONTINUEDECISION" == "Y" || "$CONTINUEDECISION" == "y" ]]; then
				sleep 1
				continue_editing
			else
				echo ""
				echo "###--Exiting Script --##"
			fi
		fi
		;;
	[nN] | [nN][oO] )
		echo ""
		echo "###--Exiting Script--###"
		;;
	*)
		echo "Please enter a valid option!"
		echo ""
		sleep 1
		read -p "Do you want to continue? (Y/N): " CONTINUEDECISION
		if [[ "$CONTINUEDECISION" == "Y" || "$CONTINUEDECISION" == "y" ]]; then
			sleep 1
			echo "$(ls -1 -l)"
			continue_editing
		else
			echo "###--Exiting Script--###"
			fi
		;;
esac
