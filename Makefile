build:
	mkdir ${TRAVIS_BUILD_DIR}/build/ && cd ${TRAVIS_BUILD_DIR}/build/ && cmake ../ && make

test: build
	cd ${TRAVIS_BUILD_DIR}/build/Test/ && ./HexagonEngineTest
