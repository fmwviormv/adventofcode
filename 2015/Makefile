CFLAGS = -pipe -O2 -std=c99 -pedantic -Wall -Wextra -Werror
$.ALL := $.1 $.2 $.3 $.4 $.5 $.6 $.7 $.8 $.9 $.10 $.11 $.12 $.13 \
	$.14 $.15 $.16 $.17

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
	R=$$(echo -n '('\
	| ./$(@:.runtest=)) && [ "$$(echo $$R)" = "1 0" ]
	R=$$(echo -n '(())'\
	| ./$(@:.runtest=)) && [ "$$(echo $$R)" = "0 0" ]
	R=$$(echo -n '()()'\
	| ./$(@:.runtest=)) && [ "$$(echo $$R)" = "0 0" ]
	R=$$(echo -n '((('\
	| ./$(@:.runtest=)) && [ "$$(echo $$R)" = "3 0" ]
	R=$$(echo -n '(()(()('\
	| ./$(@:.runtest=)) && [ "$$(echo $$R)" = "3 0" ]
	R=$$(echo -n '))((((('\
	| ./$(@:.runtest=)) && [ "$$(echo $$R)" = "3 1" ]
	R=$$(echo -n '())'\
	| ./$(@:.runtest=)) && [ "$$(echo $$R)" = "-1 3" ]
	R=$$(echo -n '))('\
	| ./$(@:.runtest=)) && [ "$$(echo $$R)" = "-1 1" ]
	R=$$(echo -n ')))'\
	| ./$(@:.runtest=)) && [ "$$(echo $$R)" = "-3 1" ]
	R=$$(echo -n ')())())'\
	| ./$(@:.runtest=)) && [ "$$(echo $$R)" = "-3 1" ]
	R=$$(echo -n ')'\
	| ./$(@:.runtest=)) && [ "$$(echo $$R)" = "-1 1" ]
	R=$$(echo -n '()())'\
	| ./$(@:.runtest=)) && [ "$$(echo $$R)" = "-1 5" ]

$.2.build: $.2
$.2.runtest: $.2.build
	R=$$(echo 2x3x4\
	| ./$(@:.runtest=)) && [ "$$(echo $$R)" = "58 34" ]
	R=$$(echo 1x1x10\
	| ./$(@:.runtest=)) && [ "$$(echo $$R)" = "43 14" ]

$.3.build: $.3
$.3.runtest: $.3.build
	R=$$(echo -n '>'\
	| ./$(@:.runtest=)) && [ "$$(echo $$R)" = "2 2" ]
	R=$$(echo -n '^v'\
	| ./$(@:.runtest=)) && [ "$$(echo $$R)" = "2 3" ]
	R=$$(echo -n '^>v<'\
	| ./$(@:.runtest=)) && [ "$$(echo $$R)" = "4 3" ]
	R=$$(echo -n '^v^v^v^v^v'\
	| ./$(@:.runtest=)) && [ "$$(echo $$R)" = "2 11" ]

$.4.build: $.4
$.4.runtest: $.4.build
	R=$$(echo abcdef\
	| ./$(@:.runtest=)) && [ "$$(echo $$R)" = "609043 6742839" ]
	R=$$(echo pqrstuv\
	| ./$(@:.runtest=)) && [ "$$(echo $$R)" = "1048970 5714438" ]

$.5.build: $.5
$.5.runtest: $.5.build
	R=$$(echo ugknbfddgicrmopn\
	| ./$(@:.runtest=)) && [ "$$(echo $$R)" = "1 0" ]
	R=$$(echo aaa\
	| ./$(@:.runtest=)) && [ "$$(echo $$R)" = "1 0" ]
	R=$$(echo jchzalrnumimnmhp\
	| ./$(@:.runtest=)) && [ "$$(echo $$R)" = "0 0" ]
	R=$$(echo haegwjzuvuyypxyu\
	| ./$(@:.runtest=)) && [ "$$(echo $$R)" = "0 0" ]
	R=$$(echo dvszwmarrgswjxmb\
	| ./$(@:.runtest=)) && [ "$$(echo $$R)" = "0 0" ]
	R=$$(echo qjhvhtzxzqqjkmpb\
	| ./$(@:.runtest=)) && [ "$$(echo $$R)" = "0 1" ]
	R=$$(echo xxyxx\
	| ./$(@:.runtest=)) && [ "$$(echo $$R)" = "0 1" ]
	R=$$(echo uurcxstgmygtbstg\
	| ./$(@:.runtest=)) && [ "$$(echo $$R)" = "0 0" ]
	R=$$(echo ieodomkazucvgmuy\
	| ./$(@:.runtest=)) && [ "$$(echo $$R)" = "0 0" ]

$.6.build: $.6
$.6.runtest: $.6.build
	R=$$(echo turn on 0,0 through 999,999\
	| ./$(@:.runtest=)) && [ "$$(echo $$R)" = "1000000 1000000" ]
	R=$$(echo toggle 0,0 through 999,0\
	| ./$(@:.runtest=)) && [ "$$(echo $$R)" = "1000 2000" ]
	R=$$(echo turn off 499,499 through 500,500\
	| ./$(@:.runtest=)) && [ "$$(echo $$R)" = "0 0" ]
	R=$$(echo turn on 0,0 through 0,0\
	| ./$(@:.runtest=)) && [ "$$(echo $$R)" = "1 1" ]
	R=$$(echo toggle 0,0 through 999,999\
	| ./$(@:.runtest=)) && [ "$$(echo $$R)" = "1000000 2000000" ]

$.7.build: $.7
$.7.runtest: $.7.build
	R=$$(echo -e '7 LSHIFT b -> a\n1 -> b'\
	| ./$(@:.runtest=)) && [ "$$(echo $$R)" = "14 49152" ]

$.8.build: $.8
$.8.runtest: $.8.build
	R=$$(echo -e '""\n"abc"\n"aaa\\"aaa"\n"\\x27"'\
	| ./$(@:.runtest=)) && [ "$$(echo $$R)" = "12 19" ]

$.9.build: $.9
$.9.runtest: $.9.build
	R=$$(echo -e London to Dublin = 464\\nLondon to Belfast\
	= 518\\nDublin to Belfast = 141\
	| ./$(@:.runtest=)) && [ "$$(echo $$R)" = "605 982" ]

$.10.build: $.10
$.10.runtest: $.10.build
	R=$$(echo 22\
	| ./$(@:.runtest=)) && [ "$$(echo $$R)" = "2 2" ]
	R=$$(echo 1\
	| ./$(@:.runtest=)) && [ "$$(echo $$R)" = "82350 1166642" ]
	R=$$(echo 122\
	| ./$(@:.runtest=)) && [ "$$(echo $$R)" = "82352 1166644" ]

$.11.build: $.11
$.11.runtest: $.11.build
	R=$$(echo abcdefgh\
	| ./$(@:.runtest=)) && [ "$$(echo $$R)" = "abcdffaa abcdffbb" ]
	R=$$(echo ghijklmn\
	| ./$(@:.runtest=)) && [ "$$(echo $$R)" = "ghjaabcc ghjbbcdd" ]

$.12.build: $.12
$.12.runtest: $.12.build
	R=$$(echo '[1,2,3]'\
	| ./$(@:.runtest=)) && [ "$$(echo $$R)" = "6 6" ]
	R=$$(echo '{"a":2,"b":4}'\
	| ./$(@:.runtest=)) && [ "$$(echo $$R)" = "6 6" ]
	R=$$(echo '[[[3]]]'\
	| ./$(@:.runtest=)) && [ "$$(echo $$R)" = "3 3" ]
	R=$$(echo '{"a":{"b":4},"c":-1}'\
	| ./$(@:.runtest=)) && [ "$$(echo $$R)" = "3 3" ]
	R=$$(echo '{"a":[-1,1]}'\
	| ./$(@:.runtest=)) && [ "$$(echo $$R)" = "0 0" ]
	R=$$(echo '[-1,{"a":1}]'\
	| ./$(@:.runtest=)) && [ "$$(echo $$R)" = "0 0" ]
	R=$$(echo '[]'\
	| ./$(@:.runtest=)) && [ "$$(echo $$R)" = "0 0" ]
	R=$$(echo '{}'\
	| ./$(@:.runtest=)) && [ "$$(echo $$R)" = "0 0" ]
	R=$$(echo '[1,{"c":"red","b":2},3]'\
	| ./$(@:.runtest=)) && [ "$$(echo $$R)" = "6 4" ]
	R=$$(echo '{"d":"red","e":[1,2,3,4],"f":5}'\
	| ./$(@:.runtest=)) && [ "$$(echo $$R)" = "15 0" ]
	R=$$(echo '[1,"red",5]'\
	| ./$(@:.runtest=)) && [ "$$(echo $$R)" = "6 6" ]

$.13.build: $.13
$.13.runtest: $.13.build
	R=$$(echo -e Alice would gain 54 happiness units by sitting\
	next to Bob.\\nAlice would lose 79 happiness units by sitting\
	next to Carol.\\nAlice would lose 2 happiness units by sitting\
	next to David.\\nBob would gain 83 happiness units by sitting\
	next to Alice.\\nBob would lose 7 happiness units by sitting\
	next to Carol.\\nBob would lose 63 happiness units by sitting\
	next to David.\\nCarol would lose 62 happiness units by sitting\
	next to Alice.\\nCarol would gain 60 happiness units by sitting\
	next to Bob.\\nCarol would gain 55 happiness units by sitting\
	next to David.\\nDavid would gain 46 happiness units by sitting\
	next to Alice.\\nDavid would lose 7 happiness units by sitting\
	next to Bob.\\nDavid would gain 41 happiness units by sitting\
	next to Carol.\
	| ./$(@:.runtest=)) && [ "$$(echo $$R)" = "330 286" ]

$.14.build: $.14
$.14.runtest: $.14.build
	R=$$(echo -e Comet can fly 14 km/s for 10 seconds, but then\
	must rest for 127 seconds.\\nDancer can fly 16 km/s for 11\
	seconds, but then must rest for 162 seconds.\
	| ./$(@:.runtest=)) && [ "$$(echo $$R)" = "2660 1564" ]

$.15.build: $.15
$.15.runtest: $.15.build
	R=$$(echo -e Butterscotch: capacity -1, durability -2,\
	flavor 6, texture 3, calories 8\\nCinnamon: capacity 2,\
	durability 3, flavor -2, texture -1, calories 3\
	| ./$(@:.runtest=)) && [ "$$(echo $$R)" = "62842880 57600000" ]

$.16.build: $.16
$.16.runtest: $.16.build
	R=$$(echo -e Sue 1: cats: 6\\nSue 2: cats: 7\\nSue 3: cats: 8\
	| ./$(@:.runtest=)) && [ "$$(echo $$R)" = "2 3" ]

$.17.build: $.17
$.17.runtest: $.17.build
	R=$$(echo -e '120\n90\n60\n30\n30'\
	| ./$(@:.runtest=)) && [ "$$(echo $$R)" = "4 3" ]
