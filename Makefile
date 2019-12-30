build: create-build-dir
	cd build/ && cmake ../ && make

test: build
	./build/Test/HexagonEngineTest

clean:
	rm -rf build/ 

create-build-dir:
	mkdir -p build/

# TODO
# The build directory should be changed
test-windows: build-windows
	cd build/Debug/ && HexagonEngineTest

# Should be build using msbuild ${project_name}.sln
build-windows: run-cmake-windows
	cd build/ && msbuild HexagonEgnine.sln

run-cmake-windows: create-build-dir-windows
	cd build/ && cmake ../

create-build-dir-windows:
	mkdir build/