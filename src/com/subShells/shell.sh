# Process control
# if control
if [ $a == $b ]; then
   echo "a 等于 b"
elif [ $a -gt $b ]; then
   echo "a 大于 b"
elif [ $a -lt $b ]; then
   echo "a 小于 b"
else
   echo "没有符合的条件"
fi

if test $[num1] -eq $[num2]; then
    echo '两个数字相等!'
else
    echo '两个数字不相等!'
fi

# for control
for loop in 11 2 3 4 57
do
    echo "The value is: $loop"
done

# while control
while(( $int<=5 ))
do
    echo $int
    let "int++"		// let command
done

# until control
until condition
do
    command
done

# case control
case 值 in
case1)
    command2
    
    ;;
case2）
    command2
    ;;
esac

# break control
break, continue

# let command
let a=5+4
let b=9-3 
echo $a $b
