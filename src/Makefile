all:
	$(MAKE) -C client
	$(MAKE) -C server
	mv client/client builds/
	mv server/server builds/

clean:
	$(MAKE) -C client clean
	$(MAKE) -C server clean
	rm -rf builds/*
