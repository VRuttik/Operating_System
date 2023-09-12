#Addition of two numbers
echo Enter two numbers
read a b
c=`expr $a + $b`               # by default type is integer.
#((c=$a+$b))                   # no space allowed.
echo addition=$c
