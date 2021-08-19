comp=g++
libs= -lssl -lcrypto
apps=create-wallet
flags=-std=c++11 -Wall
mains = ./mains
transaction = ./transaction
Apps=create-wallet
generic= $(comp) $(flags) -o $@
genericApp = $(generic) $^ $(libs)

all: $(Apps)

create-wallet: $(transaction)/User.o $(mains)/create-wallet.o $(transaction)/Key.o
	$(genericApp)
%.o:%.cpp %.h
	$(generic) -c $< $(libs)
%.o:%.cpp
	$(generic) -c $< $(libs)
.PHONY clean:
	rm -rf *.o $(Apps) $(mains)/*.o $(transaction)/*.o
.PHONY remove-wallet:
	rm -rf flurbo-private.pem flurbo-public.pem