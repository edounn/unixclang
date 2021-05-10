#!/bin/bash
#Paramaters: 3 integers

#NAME : Eddie Dounn
#CS 4350 – Unix Systems Programming
#Section Number : 251
#Assignment Number : Homework 2
#Due Date : 2 / 22 / 2021 no later than 5:15 pm

echo "This Script is Designed and Implemented by Eddie Dounn

The function of This script is to:
1. Display the integer arguments that are entered.
2. Sum of the 3 integer arguments .
3. Product of the 3 integer arguments.
4. Average of the 3 integer arguments.
5. Square of each integer argument.
6. Determine that each integer argument is positive, negative or zero.
7. Determine that each integer argument is odd, or even
8. Find the all odd and even numbers between 1 and the second integer argument.
9. Find the factorial of the first integer argument.
10. Determine whether or not the third integer argument is a prime number.
11. Display the smallest of the integer arguments
12. Display the largest of the integer arguments"

#IFS=‘,’   #unsure if input with , or not is required by example

#checking if ran with 3 parameters
#if (($# != 3));
#then
#	echo "**** Error - Must input 3 integer Values"
#else
#	echo "You entered::" $1 "," $2 "," $3
#fi
printf "\n"
echo "Enter 3 integer Values: "
read -a integers

#for elem in ${integers[@]}
#do
#  echo $elem
#done

len=${#integers[@]}
restartFlag=no
#echo $len
printf "\n"
if [ $len != 3 ]; then
		echo "**** Error - Must input 3 integer Values"
		printf "\n"
		echo "Run the script again Y | N ?"
		read runAgain
		if [ $runAgain == "y" ] || [ $runAgain == "Y" ]; then
			printf "\n"
			echo "##############################"
			echo "restarting script.."
			echo "##############################"
			sh $0
		elif [ $runAgain == "n" ] || [ $runAgain == "N" ]; then
			echo "##############################"
			echo "SP21_HW2_Eddie_Dounn completed."
			echo "##############################"

			exit 0
		else
			echo "**** Error - Must input Y or N"

		fi

else
	#1
	echo "1) You entered:" ${integers[@]}

	#2
	sum=`expr ${integers[0]} + ${integers[1]} + ${integers[2]}`
	echo "2)" ${integers[0]} "+" ${integers[1]} "+" ${integers[2]} "=" $sum

	#3
	prod=`expr ${integers[0]} \* ${integers[1]} \* ${integers[2]}`
	echo "3)" ${integers[0]} "*" ${integers[1]} "*" ${integers[2]} "=" $prod

	#4
	avg=`expr $sum / $len`
	echo "4)" "(" ${integers[0]} "+" ${integers[1]} "+" ${integers[2]} ") / 3 =" $avg

	#5
	sqr0=`expr ${integers[0]} \* ${integers[0]}`
	sqr1=`expr ${integers[1]} \* ${integers[1]}`
	sqr2=`expr ${integers[1]} \* ${integers[1]}`
	echo "5)" ${integers[0]} "*" ${integers[0]} "=" $sqr0 "," ${integers[1]} "*" ${integers[1]} "=" $sqr1 "," ${integers[2]} "*" ${integers[2]} "=" $sqr2

	#6    note ?why did i have to use 'if test' here instead?
	displayNumSix="6) "
	for elem in ${integers[@]}
	do
		if test "$elem" -eq 0;then
			displayNumSix+="$elem"" is zero, "
		elif test "$elem" -gt 0; then
			displayNumSix+="$elem"" is postive, "
		else
			displayNumSix+="$elem"" is negative, "
		fi
	done
	echo "$displayNumSix"




	#7
	echo "7)"
	for elem in ${integers[@]}
	do
		if test $(expr $elem % 2) == 0;then
	  	echo " " $elem "is even"
		else
			echo " " $elem "is odd"
		fi
	done



		#8  odd and even ints from 1 to second arg
		middle=${integers[1]}
		echo "8) All odd and even from 1 to "${integers[1]}:
		while [ $middle -gt 0 ]
		do
			if test $(expr $middle % 2) == 0;then
		  	echo " " $middle "is even"
			else
				echo " " $middle "is odd"
			fi
  		middle=$((middle - 1))
		done


			#9  factorial  *todo factorial >=1
			num=${integers[0]}
			if [ $num -lt 0 ]; then
				echo "9) Negative factorial" $num "skipped."
			else

		    fact=1
				while [ $num -gt 0 ]
				do
		  		fact=$((fact * num))
		  		num=$((num - 1))
				done
				  echo "9) Factoral of" ${integers[0]}: $fact
			fi


			#10 is 3rd arg a prime number?
			#Resource used for help at https://www.log2base2.com/shell-script-examples/loop/shell-script-to-find-factorial-of-a-number.html
			isPrime=${integers[2]}
			i=2
			flag=0
			while test $i -le `expr $isPrime / 2`
			do
				if test `expr $isPrime % $i` -eq 0;
				then
					flag=1
				fi
				i=`expr $i + 1`
			done
			if test $flag -eq 1
			then
				echo "10)" $isPrime "is Not Prime"
			else
				echo "10)" $isPrime "is Prime"
			fi






  #11 & 12 max and min
  max=${integers[0]}
  min=${integers[0]}

  for i in "${integers[@]}"
  do
      if [[ "$i" -gt "$max" ]]; then
          max="$i"
      fi

      if [[ "$i" -lt "$min" ]]; then
          min="$i"
      fi
  done


  echo "11) The Smallest integer is:" $min
  echo "12) The Largest integer is:" $max

printf "\n"

echo "Run the script again Y | N ?"
read runAgain
if [ $runAgain == "y" ] || [ $runAgain == "Y" ]; then
	printf "\n"
	echo "##############################"
	echo "restarting script.."
	echo "##############################"
	sh $0
else
	echo "##############################"
	echo "SP21_HW2_Eddie_Dounn completed."
	echo "##############################"

	exit 0
fi

fi
