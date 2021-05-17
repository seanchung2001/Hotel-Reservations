p2: main.o Date.o Guest.o Recorder.o GuestRecorder.o StayRecorder.o UpgradeRecorder.o Hotel.o Reservation.o ResManager.o Room.o RoomArray.o Control.o View.o
	g++ -o p2 main.o Date.o Guest.o Recorder.o GuestRecorder.o StayRecorder.o UpgradeRecorder.o Hotel.o Reservation.o ResManager.o Room.o RoomArray.o Control.o View.o

main.o: main.cc Control.h
	g++ -c main.cc

Date.o: Date.h Date.cc
	g++ -c Date.cc
	
Guest.o: Guest.h Guest.cc
	g++ -c Guest.cc
	
Recorder.o: Reservation.h Recorder.h Recorder.cc
	g++ -c Recorder.cc

GuestRecorder.o: Recorder.h GuestRecorder.h GuestRecorder.cc Reservation.h
	g++ -c GuestRecorder.cc

StayRecorder.o: Recorder.h StayRecorder.h StayRecorder.cc Reservation.h
	g++ -c StayRecorder.cc
	
UpgradeRecorder.o: Recorder.h UpgradeRecorder.h UpgradeRecorder.cc Reservation.h
	g++ -c UpgradeRecorder.cc

Hotel.o: ResManager.h Hotel.h Hotel.cc RoomArray.h Room.h Guest.h
	g++ -c Hotel.cc
	
Reservation.o: Guest.h Room.h Date.h Reservation.h Reservation.cc
	g++ -c Reservation.cc

ResManager.o: defs.h Reservation.h ResManager.h ResManager.cc RoomArray.h Recorder.h Hotel.h
	g++ -c ResManager.cc

Room.o: defs.h Room.h Room.cc
	g++ -c Room.cc
	
RoomArray.o: defs.h Room.h RoomArray.h RoomArray.cc
	g++ -c RoomArray.cc
	
Control.o: Hotel.h ResManager.h Recorder.h StayRecorder.h GuestRecorder.h UpgradeRecorder.h Control.h Control.cc View.h
	g++ -c Control.cc

View.o: View.h View.cc
	g++ -c View.cc
	
clean:
	rm -f *.o p2
