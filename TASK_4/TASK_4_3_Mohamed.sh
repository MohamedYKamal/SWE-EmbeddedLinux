#!/bin/bash
Days=("Monday" "Tuesday" "Wednesday" "Thursday" "Friday" "Saturday" "Sunday")


Today=$1
MeetAfter=$2


Result=$(echo "($Today + $MeetAfter) % 7 " | bc)

MeetingDay=${Days[$Result-1]}

echo $MeetingDay