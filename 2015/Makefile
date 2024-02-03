CFLAGS = -pipe -O2 -std=c99 -pedantic -Wall -Wextra -Werror
$.ALL := $.1 $.2 $.3 $.4 $.5 $.6 $.7 $.8 $.9 $.10 $.11 $.12 $.13

T := $($.ALL)
all: $(T:=.build)
test: $(T:=.runtest)
clean: $(T:=.doclean)
$(.:/=).build: $($.ALL:=.build)
$(.:/=).runtest: $($.ALL:=.runtest)
$(.:/=).doclean: $($.ALL:=.doclean)
$($.ALL:=.doclean):
	rm -f $(@:.doclean=)

$.1.build: $.1
$.1.runtest: $.1.build
	R=$$(echo -n '(' | ./$(@:.runtest=))\
	&& [ "$$(echo $$R)" = "1 0" ]
	R=$$(echo -n '(())' | ./$(@:.runtest=))\
	&& [ "$$(echo $$R)" = "0 0" ]
	R=$$(echo -n '()()' | ./$(@:.runtest=))\
	&& [ "$$(echo $$R)" = "0 0" ]
	R=$$(echo -n '(((' | ./$(@:.runtest=))\
	&& [ "$$(echo $$R)" = "3 0" ]
	R=$$(echo -n '(()(()(' | ./$(@:.runtest=))\
	&& [ "$$(echo $$R)" = "3 0" ]
	R=$$(echo -n '))(((((' | ./$(@:.runtest=))\
	&& [ "$$(echo $$R)" = "3 1" ]
	R=$$(echo -n '())' | ./$(@:.runtest=))\
	&& [ "$$(echo $$R)" = "-1 3" ]
	R=$$(echo -n '))(' | ./$(@:.runtest=))\
	&& [ "$$(echo $$R)" = "-1 1" ]
	R=$$(echo -n ')))' | ./$(@:.runtest=))\
	&& [ "$$(echo $$R)" = "-3 1" ]
	R=$$(echo -n ')())())' | ./$(@:.runtest=))\
	&& [ "$$(echo $$R)" = "-3 1" ]
	R=$$(echo -n ')' | ./$(@:.runtest=))\
	&& [ "$$(echo $$R)" = "-1 1" ]
	R=$$(echo -n '()())' | ./$(@:.runtest=))\
	&& [ "$$(echo $$R)" = "-1 5" ]

$.2.build: $.2
$.2.runtest: $.2.build
	R=$$(echo -n '2x3x4' | ./$(@:.runtest=))\
	&& [ "$$(echo $$R)" = "58 34" ]
	R=$$(echo -n '1x1x10' | ./$(@:.runtest=))\
	&& [ "$$(echo $$R)" = "43 14" ]

$.3.build: $.3
$.3.runtest: $.3.build
	R=$$(echo -n '>' | ./$(@:.runtest=))\
	&& [ "$$(echo $$R)" = "2 2" ]
	R=$$(echo -n '^v' | ./$(@:.runtest=))\
	&& [ "$$(echo $$R)" = "2 3" ]
	R=$$(echo -n '^>v<' | ./$(@:.runtest=))\
	&& [ "$$(echo $$R)" = "4 3" ]
	R=$$(echo -n '^v^v^v^v^v' | ./$(@:.runtest=))\
	&& [ "$$(echo $$R)" = "2 11" ]

$.4.build: $.4
$.4.runtest: $.4.build
	R=$$(echo 'abcdef' | ./$(@:.runtest=))\
	&& [ "$$(echo $$R)" = "609043 6742839" ]
	R=$$(echo 'pqrstuv' | ./$(@:.runtest=))\
	&& [ "$$(echo $$R)" = "1048970 5714438" ]

$.5.build: $.5
$.5.runtest: $.5.build
	R=$$(echo -n 'ugknbfddgicrmopn' | ./$(@:.runtest=))\
	&& [ "$$(echo $$R)" = "1 0" ]
	R=$$(echo -n 'aaa' | ./$(@:.runtest=))\
	&& [ "$$(echo $$R)" = "1 0" ]
	R=$$(echo -n 'jchzalrnumimnmhp' | ./$(@:.runtest=))\
	&& [ "$$(echo $$R)" = "0 0" ]
	R=$$(echo -n 'haegwjzuvuyypxyu' | ./$(@:.runtest=))\
	&& [ "$$(echo $$R)" = "0 0" ]
	R=$$(echo -n 'dvszwmarrgswjxmb' | ./$(@:.runtest=))\
	&& [ "$$(echo $$R)" = "0 0" ]
	R=$$(echo -n 'qjhvhtzxzqqjkmpb' | ./$(@:.runtest=))\
	&& [ "$$(echo $$R)" = "0 1" ]
	R=$$(echo -n 'xxyxx' | ./$(@:.runtest=))\
	&& [ "$$(echo $$R)" = "0 1" ]
	R=$$(echo -n 'uurcxstgmygtbstg' | ./$(@:.runtest=))\
	&& [ "$$(echo $$R)" = "0 0" ]
	R=$$(echo -n 'ieodomkazucvgmuy' | ./$(@:.runtest=))\
	&& [ "$$(echo $$R)" = "0 0" ]

$.6.build: $.6
$.6.runtest: $.6.build
	R=$$(echo 'turn on 0,0 through 999,999' | ./$(@:.runtest=))\
	&& [ "$$(echo $$R)" = "1000000 1000000" ]
	R=$$(echo 'toggle 0,0 through 999,0' | ./$(@:.runtest=))\
	&& [ "$$(echo $$R)" = "1000 2000" ]
	R=$$(echo 'turn off 499,499 through 500,500' | ./$(@:.runtest=))\
	&& [ "$$(echo $$R)" = "0 0" ]
	R=$$(echo 'turn on 0,0 through 0,0' | ./$(@:.runtest=))\
	&& [ "$$(echo $$R)" = "1 1" ]
	R=$$(echo 'toggle 0,0 through 999,999' | ./$(@:.runtest=))\
	&& [ "$$(echo $$R)" = "1000000 2000000" ]

$.7.build: $.7
$.7.runtest: $.7.build
	R=$$(echo -e '7 LSHIFT b -> a\n1 -> b' | ./$(@:.runtest=))\
	&& [ "$$(echo $$R)" = "14 49152" ]

$.8.build: $.8
$.8.runtest: $.8.build
	R=$$(echo -e '""\n"abc"\n"aaa\\"aaa"\n"\\x27"' | ./$(@:.runtest=))\
	&& [ "$$(echo $$R)" = "12 19" ]

$.9.build: $.9
$.9.runtest: $.9.build
	R=$$((echo 'London to Dublin = 464'\
	&& echo 'London to Belfast = 518'\
	&& echo 'Dublin to Belfast = 141') | ./$(@:.runtest=))\
	&& [ "$$(echo $$R)" = "605 982" ]

$.10.build: $.10
$.10.runtest: $.10.build
	R=$$(echo 22 | ./$(@:.runtest=))\
	&& [ "$$(echo $$R)" = "2 2" ]
	R=$$(echo 1 | ./$(@:.runtest=))\
	&& [ "$$(echo $$R)" = "82350 1166642" ]
	R=$$(echo 122 | ./$(@:.runtest=))\
	&& [ "$$(echo $$R)" = "82352 1166644" ]

$.11.build: $.11
$.11.runtest: $.11.build
	R=$$(echo abcdefgh | ./$(@:.runtest=))\
	&& [ "$$(echo $$R)" = "abcdffaa abcdffbb" ]
	R=$$(echo ghijklmn | ./$(@:.runtest=))\
	&& [ "$$(echo $$R)" = "ghjaabcc ghjbbcdd" ]

$.12.build: $.12
$.12.runtest: $.12.build
	R=$$(echo '[1,2,3]' | ./$(@:.runtest=))\
	&& [ "$$(echo $$R)" = "6 6" ]
	R=$$(echo '{"a":2,"b":4}' | ./$(@:.runtest=))\
	&& [ "$$(echo $$R)" = "6 6" ]
	R=$$(echo '[[[3]]]' | ./$(@:.runtest=))\
	&& [ "$$(echo $$R)" = "3 3" ]
	R=$$(echo '{"a":{"b":4},"c":-1}' | ./$(@:.runtest=))\
	&& [ "$$(echo $$R)" = "3 3" ]
	R=$$(echo '{"a":[-1,1]}' | ./$(@:.runtest=))\
	&& [ "$$(echo $$R)" = "0 0" ]
	R=$$(echo '[-1,{"a":1}]' | ./$(@:.runtest=))\
	&& [ "$$(echo $$R)" = "0 0" ]
	R=$$(echo '[]' | ./$(@:.runtest=))\
	&& [ "$$(echo $$R)" = "0 0" ]
	R=$$(echo '{}' | ./$(@:.runtest=))\
	&& [ "$$(echo $$R)" = "0 0" ]
	R=$$(echo '[1,{"c":"red","b":2},3]' | ./$(@:.runtest=))\
	&& [ "$$(echo $$R)" = "6 4" ]
	R=$$(echo '{"d":"red","e":[1,2,3,4],"f":5}' | ./$(@:.runtest=))\
	&& [ "$$(echo $$R)" = "15 0" ]
	R=$$(echo '[1,"red",5]' | ./$(@:.runtest=))\
	&& [ "$$(echo $$R)" = "6 6" ]

$.13.build: $.13
$.13.runtest: $.13.build
	R=$$((echo 'Alice would gain 54 happiness units by sitting next to Bob.'\
	&& echo 'Alice would lose 79 happiness units by sitting next to Carol.'\
	&& echo 'Alice would lose 2 happiness units by sitting next to David.'\
	&& echo 'Bob would gain 83 happiness units by sitting next to Alice.'\
	&& echo 'Bob would lose 7 happiness units by sitting next to Carol.'\
	&& echo 'Bob would lose 63 happiness units by sitting next to David.'\
	&& echo 'Carol would lose 62 happiness units by sitting next to Alice.'\
	&& echo 'Carol would gain 60 happiness units by sitting next to Bob.'\
	&& echo 'Carol would gain 55 happiness units by sitting next to David.'\
	&& echo 'David would gain 46 happiness units by sitting next to Alice.'\
	&& echo 'David would lose 7 happiness units by sitting next to Bob.'\
	&& echo 'David would gain 41 happiness units by sitting next to Carol.'\
	) | ./$(@:.runtest=)) && [ "$$(echo $$R)" = "330 286" ]
