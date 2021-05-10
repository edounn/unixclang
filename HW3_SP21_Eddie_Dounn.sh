#!/bin/bash


#CS 4350 – Unix Systems Programming
#Section Number : 251
#NAME:  Eddie Dounn
#Assignment Number: Homework 3
#Due Date: 3 / 3 / 2021

#Notes :
#1. Each of the above items must be implemented in a separate function.
#2. Must pass parameters to function for items 1 thru 5 , and 7.
#3. Must use case statement.


# Menu & intro text
introText(){
  echo "CS 4350 – Unix Systems Programming"
  echo "Section Number : 251"
  echo "NAME: Eddie Dounn"
  echo "Assignment Number: Homework 3"
  echo "Due Date: 3 / 3 / 2021"
  echo ""
  echo "The function of this script is to:"
  echo ""
  echo "1. Make directory by checking existence. Display error message if it exist."
  echo "2. Test if File Exist. If it exits then Read the File, display its size, number of"
  echo "   chars in the file, and its contents. Display a message it does not exist."
  echo "   Create the file."
  echo "3. Copy a file to another file and display the content of both files. Display a"
  echo "   message if source file does not exist. Display a message if destination file"
  echo "   does not exit , create the file , copy and display the content new file"
  echo "4. Append “Learning Scripts and Shell Programming “ to an existing File."
  echo "   Display a message it does not exist"
  echo "5. Delete an existing File. Display a message it does not exist"
  echo "6. Parse Current Date, Show Process Status"
  echo "7. Using random number generator , generate two numbers such as A and B."
  echo "   Values of generated numbers are either 0 or 1. Display Boolean expression"
  echo "   for A XOR B"
  echo "9. Exit"
  echo ""
  echo ""
  echo "Enter your choice: "
}

menuOne(){
  echo "Enter Name of the Directory to be Created: "
  read dirName

  if [ -d $dirName ]
  then
    echo "./"$dirName" already exists."
  else
    mkdir $dirName
    echo $dirName "directory is created."
  fi

}

menuTwo(){
  echo "Enter File Name:"
  read fileName
  if test -f "$fileName"; then
    echo " "
    ls -larth "$fileName"
    echo "content: "
    echo " "
    cat $fileName




  else
  echo "$fileName does not exist."
  touch $fileName
  echo "File created"
  fi
}

menuThree(){
  echo "Enter the name of the source file:"
  read sourceFile
  echo "Enter the name of the destination file:"
  read destFile

  if test -f "$sourceFile"; then
    cp $sourceFile $destFile
    echo "source file:"
    cat $sourceFile
    echo " "
    echo "destination file:"
    cat $destFile
  else
    echo "error no source does not exist"
  fi

}


menuFour(){
  echo "Enter file name:"
  read sourceFile
  if test -f "$sourceFile"; then
    echo "File Content Before Append"
    cat $sourceFile
    echo " "
    echo "File Content After Append"
    echo Learning Scripts and Shell Programming >> $sourceFile
    cat $sourceFile
  else
    echo "file does not exist"
  fi
}

menuFive(){
  echo "Enter The name of file to be deleted:"
  read sourceFile
  if test -f "$sourceFile"; then
    rm $sourceFile
    echo $sourceFile "is deleted"
  else
    echo "file does not exist"
  fi
}

menuSix(){
  echo "current date"
  date +”%m/%d/%Y”
  echo "current time"
  date +”%H:%M:%S”
}

menuSeven(){
  A=1
  B=0
  E=$(( A ^ B ))
  echo $E
}
#run menu function
introText

#reading menu item number with case per instructions
read menuItem
case "$menuItem" in
 1)
 #debug
 #echo "menu 1"
 menuOne
 ;;
 2)
 #debug
 #echo "Menu item 2"
 menuTwo
 ;;
 3)
 #debug
 #echo "menu item 3"
 menuThree
 ;;
 4)
 menuFour
 ;;
 5)
 menuFive
 ;;
 6)
 menuSix
 ;;
 7)
 menuSeven
 ;;
 9)
 echo "exit"
 exit 0
 ;;
 *)
 echo "Pick 1 through 9 please"
 ;;
esac
