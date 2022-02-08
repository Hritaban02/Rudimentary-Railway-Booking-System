# Makefile

# One single executable

a.out : main.o ApplicationTest1.o MyApplicationTest.o Date.o Station.o Passenger.o Railways.o BookingClass.o Seat.o Berth.o ZeroTierSeat.o TwoTierBerth.o ThreeTierBerth.o AC2Tier.o AC3Tier.o ACFirstClass.o FirstClass.o ACChairCar.o SecondSitting.o Sleeper.o Booking.o
	g++ main.o ApplicationTest1.o MyApplicationTest.o Date.o Station.o Passenger.o Railways.o BookingClass.o Seat.o Berth.o ZeroTierSeat.o TwoTierBerth.o ThreeTierBerth.o AC2Tier.o AC3Tier.o ACFirstClass.o FirstClass.o ACChairCar.o SecondSitting.o Sleeper.o Booking.o -o a.out
	
main.o : main.cpp 
	g++ -c -std=c++17 -W -Wall main.cpp
	
ApplicationTest1.o : ApplicationTest1.cpp 
	g++ -c -std=c++17 -W -Wall ApplicationTest1.cpp
	
MyApplicationTest.o : MyApplicationTest.cpp 
	g++ -c -std=c++17 -W -Wall MyApplicationTest.cpp
	
Date.o : Date.cpp Date.h
	g++ -c -std=c++17 -W -Wall Date.cpp
	
Station.o : Station.cpp Station.h
	g++ -c -std=c++17 -W -Wall Station.cpp	
	
Passenger.o : Passenger.cpp Passenger.h 
	g++ -c -std=c++17 -W -Wall Passenger.cpp	
	
Railways.o : Railways.cpp Railways.h
	g++ -c -std=c++17 -W -Wall Railways.cpp

BookingClass.o : BookingClass.cpp BookingClass.h
	g++ -c -std=c++17 -W -Wall BookingClass.cpp
	
Seat.o : Seat.cpp Seat.h
	g++ -c -std=c++17 -W -Wall Seat.cpp
	
Berth.o : Berth.cpp Berth.h
	g++ -c -std=c++17 -W -Wall Berth.cpp
	
ZeroTierSeat.o : ZeroTierSeat.cpp ZeroTierSeat.h
	g++ -c -std=c++17 -W -Wall ZeroTierSeat.cpp
	
TwoTierBerth.o : TwoTierBerth.cpp TwoTierBerth.h
	g++ -c -std=c++17 -W -Wall TwoTierBerth.cpp
	
ThreeTierBerth.o : ThreeTierBerth.cpp ThreeTierBerth.h
	g++ -c -std=c++17 -W -Wall ThreeTierBerth.cpp
	
AC2Tier.o : AC2Tier.cpp AC2Tier.h
	g++ -c -std=c++17 -W -Wall AC2Tier.cpp
	
AC3Tier.o : AC3Tier.cpp AC3Tier.h
	g++ -c -std=c++17 -W -Wall AC3Tier.cpp
	
ACFirstClass.o : ACFirstClass.cpp ACFirstClass.h
	g++ -c -std=c++17 -W -Wall ACFirstClass.cpp

FirstClass.o : FirstClass.cpp FirstClass.h
	g++ -c -std=c++17 -W -Wall FirstClass.cpp

ACChairCar.o : ACChairCar.cpp ACChairCar.h
	g++ -c -std=c++17 -W -Wall ACChairCar.cpp

SecondSitting.o : SecondSitting.cpp SecondSitting.h
	g++ -c -std=c++17 -W -Wall SecondSitting.cpp

Sleeper.o : Sleeper.cpp Sleeper.h
	g++ -c -std=c++17 -W -Wall Sleeper.cpp
	
Booking.o : Booking.cpp Booking.h
	g++ -c -std=c++17 -W -Wall Booking.cpp
