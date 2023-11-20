# Number is prime or not.

echo "Enter a number:"
read n

m=$((n / 2))
i=2
isPrime=0

# Checking remainder
while [ $i -le $m ]
do
    rem=$((n % i))
    if [ $rem -eq 0 ]
    then
        isPrime=1
        break
    fi
    i=$((i + 1))
done

# Checking flag
if [ $isPrime -eq 1 -o $n -eq 1 ]
then
    echo "$n is not a prime number"
else
    echo "$n is a prime number"
fi
