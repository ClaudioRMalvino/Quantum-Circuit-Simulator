#include "../include/QuantumRegister.hpp"
#include <iostream>
#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>

TEST_CASE("Hadamard on state vector produces superposition", "[hadamard]") {
    double margin = {1.0e-12};
    QuantumRegister qr(2);

    SECTION("Hadamard on |00>") {
        qr.applyGate(H_Gate,0);
        std::complex<double> firstAmp {qr.getStateVector()[0]};
        std::complex<double> secondAmp {qr.getStateVector()[1]};
        std::complex<double> thirdAmp {qr.getStateVector()[2]};
        std::complex<double> fourthAmp {qr.getStateVector()[3]};
        double expected {1.0 / std::sqrt(2.0)};

        REQUIRE_THAT(  firstAmp.real(), Catch::Matchers::WithinAbs(expected, margin)  );
        REQUIRE(  firstAmp.imag() == 0 );
        REQUIRE_THAT(  secondAmp.real(), Catch::Matchers::WithinAbs(expected, margin)  );
        REQUIRE(  firstAmp.imag() == 0 );
        REQUIRE( thirdAmp.real() == 0 );
        REQUIRE( thirdAmp.imag() == 0 );
        REQUIRE( fourthAmp.real() == 0 );
        REQUIRE( fourthAmp.imag() == 0 );
    }

    SECTION("Hadamard on |01>") {
        qr.applyGate(H_Gate,1);
        std::complex<double> firstAmp {qr.getStateVector()[0]};
        std::complex<double> secondAmp {qr.getStateVector()[1]};
        std::complex<double> thirdAmp {qr.getStateVector()[2]};
        std::complex<double> fourthAmp {qr.getStateVector()[3]};
        double expected {1.0 / std::sqrt(2.0)};

        REQUIRE_THAT(  firstAmp.real(), Catch::Matchers::WithinAbs(expected, margin)  );
        REQUIRE( firstAmp.imag() == 0 );
        REQUIRE( secondAmp.real() == 0  );
        REQUIRE( firstAmp.imag() == 0 );
        REQUIRE_THAT( thirdAmp.real(), Catch::Matchers::WithinAbs(expected, margin)  );
        REQUIRE( thirdAmp.imag() == 0 );
        REQUIRE( fourthAmp.real() == 0 );
        REQUIRE( fourthAmp.imag() == 0 );

    }
}

/** TODO: Need to run tests on operator*(Gate, Gate) to see if the overload is working as expected.
 *  TODO: Need to also run a chain of applyGate(Gate, int) to see if I get the expected result.
 *
 */
