#!/usr/bin/env bash

DIR=$1
RATE=$2
TIMEOUT=1

case $DIR in

  UP|Up|up)
    X=17
    Y=36
    ;;
  DOWN|Down|down)
    X=17
    Y=37
    ;;
  LEFT|Left|left)
    X=16
    Y=36
    ;;
  RIGHT|Right|right)
    X=16
    Y=37
    ;;
  STOP|Stop|stop)
    STOP=1
esac

send() {
	#echo -ne "$(printf "P${FORMAT}" 2 $1 $2 $3 0 0 0)" > /dev/ttyS0
	echo -ne "$(printf "P${FORMAT}" 2 $1 $2 $3 0 0 0)" | nc -w 1 -W 1 localhost 4030 &>/dev/null
}

#stty -F /dev/ttyS0 9600
HEX="\\\\x%02X"
for i in {1..7}; do FORMAT="${FORMAT}${HEX}"; done
if [ "$STOP" ]; then
  send 16 36 0
  sleep 0.1
  send 16 37 0
  sleep 0.1
  send 17 36 0
  sleep 0.1
  send 17 37 0
else
  send $X $Y $RATE
fi
sleep 1
