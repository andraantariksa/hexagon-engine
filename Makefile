build: create-build-dir
	cd build/ && cmake ../ && make

test: build
	./build/Test/HexagonEngineTest

clean:
	rm -rf build/ 

create-build-dir:
	mkdir -p build/
