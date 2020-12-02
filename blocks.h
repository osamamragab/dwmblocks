//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
	/*Icon*/	/*Command*/		/*Update Interval*/	/*Update Signal*/
  {"vol: ", "pamixer --get-volume-human", 0, 7},
  {"cpu: ", "printf '%s - %s°' $(grep 'cpu ' /proc/stat | awk '{usage=($2+$4)*100/($2+$4+$5)} END {print int(usage) \"%\"}') $(sensors -j | jq --raw-output '.\"coretemp-isa-0000\".\"Core 0\" | to_entries | .[] | select(.key | match(\"input\")) | .value')", 10, 0},
	{"ram: ", "free -h | awk '/^Mem/ { print $3 }' | sed s/i//g",	10, 0},
  {"net: ", "cat /sys/class/net/e*/operstate", 10, 0},
	{"", "date '+%a %d %b - %I:%M%p'", 60, 0},
};

//sets delimeter between status commands. NULL character ('\0') means no delimeter.
static char delim[] = " | ";
static unsigned int delimLen = 5;
