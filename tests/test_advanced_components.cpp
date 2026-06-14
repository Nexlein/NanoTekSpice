/*
** EPITECH PROJECT, 2026
** G-OOP-400-MPL-4-1-tekspice-6
** File description:
** test_advanced_components
*/

#include <criterion/criterion.h>

#include "Components/Advanced/Advanced2716.hpp"
#include "Components/Advanced/Advanced4008.hpp"
#include "Components/Advanced/Advanced4013.hpp"
#include "Components/Advanced/Advanced4017.hpp"
#include "Components/Advanced/Advanced4040.hpp"
#include "Components/Advanced/Advanced4094.hpp"
#include "Components/Advanced/Advanced4512.hpp"
#include "Components/Advanced/Advanced4514.hpp"
#include "Components/Advanced/Advanced4801.hpp"
#include "Components/Special/ClockComponent.hpp"
#include "Components/Special/InputComponent.hpp"

/// @brief Verifies that 0000 + 0000 with no carry produces 00000
Test(Advanced4008, ZeroPlusZero)
{
    nts::Advanced4008 adder;
    nts::InputComponent a1, a2, a3, a4, b1, b2, b3, b4, carry;

    adder.setLink(7, a1, 1);
    adder.setLink(5, a2, 1);
    adder.setLink(3, a3, 1);
    adder.setLink(1, a4, 1);
    adder.setLink(6, b1, 1);
    adder.setLink(4, b2, 1);
    adder.setLink(2, b3, 1);
    adder.setLink(15, b4, 1);
    adder.setLink(9, carry, 1);

    a1.setValue(nts::False);
    a2.setValue(nts::False);
    a3.setValue(nts::False);
    a4.setValue(nts::False);
    b1.setValue(nts::False);
    b2.setValue(nts::False);
    b3.setValue(nts::False);
    b4.setValue(nts::False);
    carry.setValue(nts::False);

    cr_assert_eq(adder.compute(10), nts::False);
    cr_assert_eq(adder.compute(11), nts::False);
    cr_assert_eq(adder.compute(12), nts::False);
    cr_assert_eq(adder.compute(13), nts::False);
    cr_assert_eq(adder.compute(14), nts::False);
}

/// @brief Verifies that 0001 + 0001 produces 00010
Test(Advanced4008, OnePlusOne)
{
    nts::Advanced4008 adder;
    nts::InputComponent a1, a2, a3, a4, b1, b2, b3, b4, carry;

    adder.setLink(7, a1, 1);
    adder.setLink(5, a2, 1);
    adder.setLink(3, a3, 1);
    adder.setLink(1, a4, 1);
    adder.setLink(6, b1, 1);
    adder.setLink(4, b2, 1);
    adder.setLink(2, b3, 1);
    adder.setLink(15, b4, 1);
    adder.setLink(9, carry, 1);

    a1.setValue(nts::True);
    a2.setValue(nts::False);
    a3.setValue(nts::False);
    a4.setValue(nts::False);
    b1.setValue(nts::True);
    b2.setValue(nts::False);
    b3.setValue(nts::False);
    b4.setValue(nts::False);
    carry.setValue(nts::False);

    cr_assert_eq(adder.compute(10), nts::False);
    cr_assert_eq(adder.compute(11), nts::True);
    cr_assert_eq(adder.compute(12), nts::False);
    cr_assert_eq(adder.compute(13), nts::False);
    cr_assert_eq(adder.compute(14), nts::False);
}

/// @brief Verifies that 1111 + 0001 produces overflow
Test(Advanced4008, FifteenPlusOne)
{
    nts::Advanced4008 adder;
    nts::InputComponent a1, a2, a3, a4, b1, b2, b3, b4, carry;

    adder.setLink(7, a1, 1);
    adder.setLink(5, a2, 1);
    adder.setLink(3, a3, 1);
    adder.setLink(1, a4, 1);
    adder.setLink(6, b1, 1);
    adder.setLink(4, b2, 1);
    adder.setLink(2, b3, 1);
    adder.setLink(15, b4, 1);
    adder.setLink(9, carry, 1);

    a1.setValue(nts::True);
    a2.setValue(nts::True);
    a3.setValue(nts::True);
    a4.setValue(nts::True);
    b1.setValue(nts::True);
    b2.setValue(nts::False);
    b3.setValue(nts::False);
    b4.setValue(nts::False);
    carry.setValue(nts::False);

    cr_assert_eq(adder.compute(10), nts::False);
    cr_assert_eq(adder.compute(11), nts::False);
    cr_assert_eq(adder.compute(12), nts::False);
    cr_assert_eq(adder.compute(13), nts::False);
    cr_assert_eq(adder.compute(14), nts::True);
}

/// @brief Verifies that 0000 + 0000 with carry-in set produces 00001
Test(Advanced4008, WithCarryIn)
{
    nts::Advanced4008 adder;
    nts::InputComponent a1, a2, a3, a4, b1, b2, b3, b4, carry;

    adder.setLink(7, a1, 1);
    adder.setLink(5, a2, 1);
    adder.setLink(3, a3, 1);
    adder.setLink(1, a4, 1);
    adder.setLink(6, b1, 1);
    adder.setLink(4, b2, 1);
    adder.setLink(2, b3, 1);
    adder.setLink(15, b4, 1);
    adder.setLink(9, carry, 1);

    a1.setValue(nts::False);
    a2.setValue(nts::False);
    a3.setValue(nts::False);
    a4.setValue(nts::False);
    b1.setValue(nts::False);
    b2.setValue(nts::False);
    b3.setValue(nts::False);
    b4.setValue(nts::False);
    carry.setValue(nts::True);

    cr_assert_eq(adder.compute(10), nts::True);
    cr_assert_eq(adder.compute(11), nts::False);
    cr_assert_eq(adder.compute(12), nts::False);
    cr_assert_eq(adder.compute(13), nts::False);
    cr_assert_eq(adder.compute(14), nts::False);
}

/// @brief Verifies that an Undefined input propagates Undefined to all outputs
Test(Advanced4008, UndefinedInput)
{
    nts::Advanced4008 adder;
    nts::InputComponent a1, a2, a3, a4, b1, b2, b3, b4, carry;

    adder.setLink(7, a1, 1);
    adder.setLink(5, a2, 1);
    adder.setLink(3, a3, 1);
    adder.setLink(1, a4, 1);
    adder.setLink(6, b1, 1);
    adder.setLink(4, b2, 1);
    adder.setLink(2, b3, 1);
    adder.setLink(15, b4, 1);
    adder.setLink(9, carry, 1);

    a1.setValue(nts::Undefined);
    a2.setValue(nts::False);
    a3.setValue(nts::False);
    a4.setValue(nts::False);
    b1.setValue(nts::False);
    b2.setValue(nts::False);
    b3.setValue(nts::False);
    b4.setValue(nts::False);
    carry.setValue(nts::False);

    cr_assert_eq(adder.compute(10), nts::Undefined);
    cr_assert_eq(adder.compute(14), nts::Undefined);
}

/// @brief Verifies that 0111 + 0111 produces 01110 (7 + 7 = 14)
Test(Advanced4008, SevenPlusSeven)
{
    nts::Advanced4008 adder;
    nts::InputComponent a1, a2, a3, a4, b1, b2, b3, b4, carry;

    adder.setLink(7, a1, 1);
    adder.setLink(5, a2, 1);
    adder.setLink(3, a3, 1);
    adder.setLink(1, a4, 1);
    adder.setLink(6, b1, 1);
    adder.setLink(4, b2, 1);
    adder.setLink(2, b3, 1);
    adder.setLink(15, b4, 1);
    adder.setLink(9, carry, 1);

    a1.setValue(nts::True);
    a2.setValue(nts::True);
    a3.setValue(nts::True);
    a4.setValue(nts::False);
    b1.setValue(nts::True);
    b2.setValue(nts::True);
    b3.setValue(nts::True);
    b4.setValue(nts::False);
    carry.setValue(nts::False);

    cr_assert_eq(adder.compute(10), nts::False);
    cr_assert_eq(adder.compute(11), nts::True);
    cr_assert_eq(adder.compute(12), nts::True);
    cr_assert_eq(adder.compute(13), nts::True);
    cr_assert_eq(adder.compute(14), nts::False);
}

/// @brief Verifies that computing on invalid pin numbers returns Undefined
Test(Advanced4008, InvalidPin)
{
    nts::Advanced4008 adder;
    cr_assert_eq(adder.compute(0), nts::Undefined);
    cr_assert_eq(adder.compute(99), nts::Undefined);
}

/// @brief Verifies first flip-flop asynchronous set: normal output=True, inverted output=False
Test(Advanced4013, FirstFlipFlopAsyncSet)
{
    nts::Advanced4013 ff;
    nts::InputComponent data, set, reset, clk;

    ff.setLink(5, data, 1);
    ff.setLink(6, set, 1);
    ff.setLink(4, reset, 1);
    ff.setLink(3, clk, 1);

    data.setValue(nts::False);
    set.setValue(nts::True);
    reset.setValue(nts::False);
    clk.setValue(nts::False);

    cr_assert_eq(ff.compute(1), nts::True);
    cr_assert_eq(ff.compute(2), nts::False);
}

/// @brief Verifies first flip-flop asynchronous reset: normal output=False, inverted output=True
Test(Advanced4013, FirstFlipFlopAsyncReset)
{
    nts::Advanced4013 ff;
    nts::InputComponent data, set, reset, clk;

    ff.setLink(5, data, 1);
    ff.setLink(6, set, 1);
    ff.setLink(4, reset, 1);
    ff.setLink(3, clk, 1);

    data.setValue(nts::False);
    set.setValue(nts::False);
    reset.setValue(nts::True);
    clk.setValue(nts::False);

    cr_assert_eq(ff.compute(1), nts::False);
    cr_assert_eq(ff.compute(2), nts::True);
}

/// @brief Verifies first flip-flop with both set and reset active: normal output=True, inverted output=True
Test(Advanced4013, FirstFlipFlopSetAndResetActive)
{
    nts::Advanced4013 ff;
    nts::InputComponent data, set, reset, clk;

    ff.setLink(5, data, 1);
    ff.setLink(6, set, 1);
    ff.setLink(4, reset, 1);
    ff.setLink(3, clk, 1);

    data.setValue(nts::False);
    set.setValue(nts::True);
    reset.setValue(nts::True);
    clk.setValue(nts::False);

    cr_assert_eq(ff.compute(1), nts::True);
    cr_assert_eq(ff.compute(2), nts::True);
}

/// @brief Verifies second flip-flop asynchronous set: normal output=True, inverted output=False
Test(Advanced4013, SecondFlipFlopAsyncSet)
{
    nts::Advanced4013 ff;
    nts::InputComponent data, set, reset, clk;

    ff.setLink(9, data, 1);
    ff.setLink(8, set, 1);
    ff.setLink(10, reset, 1);
    ff.setLink(11, clk, 1);

    data.setValue(nts::False);
    set.setValue(nts::True);
    reset.setValue(nts::False);
    clk.setValue(nts::False);

    cr_assert_eq(ff.compute(13), nts::True);
    cr_assert_eq(ff.compute(12), nts::False);
}

/// @brief Verifies second flip-flop asynchronous reset: normal output=False, inverted output=True
Test(Advanced4013, SecondFlipFlopAsyncReset)
{
    nts::Advanced4013 ff;
    nts::InputComponent data, set, reset, clk;

    ff.setLink(9, data, 1);
    ff.setLink(8, set, 1);
    ff.setLink(10, reset, 1);
    ff.setLink(11, clk, 1);

    data.setValue(nts::False);
    set.setValue(nts::False);
    reset.setValue(nts::True);
    clk.setValue(nts::False);

    cr_assert_eq(ff.compute(13), nts::False);
    cr_assert_eq(ff.compute(12), nts::True);
}

/// @brief Verifies that computing on invalid pin numbers returns Undefined
Test(Advanced4013, InvalidPin)
{
    nts::Advanced4013 ff;
    cr_assert_eq(ff.compute(0), nts::Undefined);
    cr_assert_eq(ff.compute(99), nts::Undefined);
}

/// @brief Verifies the Johnson counter initial state: output 0 (pin 3) is True, carry (pin 12) is True
Test(Advanced4017, InitialState)
{
    nts::Advanced4017 counter;
    nts::InputComponent cl0, cl1, mr;

    counter.setLink(14, cl0, 1);
    counter.setLink(13, cl1, 1);
    counter.setLink(15, mr, 1);

    cl0.setValue(nts::False);
    cl1.setValue(nts::False);
    mr.setValue(nts::False);

    cr_assert_eq(counter.compute(3), nts::True);
    cr_assert_eq(counter.compute(2), nts::False);
    cr_assert_eq(counter.compute(4), nts::False);
    cr_assert_eq(counter.compute(12), nts::True);
}

/// @brief Verifies that master reset forces the counter back to state 0
Test(Advanced4017, MasterReset)
{
    nts::Advanced4017 counter;
    nts::InputComponent cl0, cl1, mr;

    counter.setLink(14, cl0, 1);
    counter.setLink(13, cl1, 1);
    counter.setLink(15, mr, 1);

    cl0.setValue(nts::False);
    cl1.setValue(nts::False);
    mr.setValue(nts::True);

    cr_assert_eq(counter.compute(3), nts::True);
    cr_assert_eq(counter.compute(2), nts::False);
}

/// @brief Verifies that computing on an invalid pin number returns Undefined
Test(Advanced4017, InvalidPin)
{
    nts::Advanced4017 counter;
    nts::InputComponent cl0, cl1, mr;

    counter.setLink(14, cl0, 1);
    counter.setLink(13, cl1, 1);
    counter.setLink(15, mr, 1);

    cl0.setValue(nts::False);
    cl1.setValue(nts::False);
    mr.setValue(nts::False);

    cr_assert_eq(counter.compute(99), nts::Undefined);
}

/// @brief Verifies the 12-bit binary counter initial state: all 12 output bits are False
Test(Advanced4040, InitialState)
{
    nts::Advanced4040 counter;
    nts::InputComponent clk, reset;

    counter.setLink(10, clk, 1);
    counter.setLink(11, reset, 1);

    clk.setValue(nts::False);
    reset.setValue(nts::False);

    cr_assert_eq(counter.compute(9), nts::False);
    cr_assert_eq(counter.compute(7), nts::False);
    cr_assert_eq(counter.compute(6), nts::False);
    cr_assert_eq(counter.compute(5), nts::False);
    cr_assert_eq(counter.compute(3), nts::False);
    cr_assert_eq(counter.compute(2), nts::False);
    cr_assert_eq(counter.compute(4), nts::False);
    cr_assert_eq(counter.compute(13), nts::False);
    cr_assert_eq(counter.compute(12), nts::False);
    cr_assert_eq(counter.compute(14), nts::False);
    cr_assert_eq(counter.compute(15), nts::False);
    cr_assert_eq(counter.compute(1), nts::False);
}

/// @brief Verifies that asserting reset forces all counter outputs to False
Test(Advanced4040, Reset)
{
    nts::Advanced4040 counter;
    nts::InputComponent clk, reset;

    counter.setLink(10, clk, 1);
    counter.setLink(11, reset, 1);

    clk.setValue(nts::False);
    reset.setValue(nts::True);

    cr_assert_eq(counter.compute(9), nts::False);
    cr_assert_eq(counter.compute(7), nts::False);
}

/// @brief Verifies that computing on an invalid pin number returns Undefined
Test(Advanced4040, InvalidPin)
{
    nts::Advanced4040 counter;
    nts::InputComponent clk, reset;

    counter.setLink(10, clk, 1);
    counter.setLink(11, reset, 1);

    clk.setValue(nts::False);
    reset.setValue(nts::False);

    cr_assert_eq(counter.compute(99), nts::Undefined);
}

/// @brief Verifies that shift register outputs start as Undefined before any clock edge
Test(Advanced4094, InitialUndefined)
{
    nts::Advanced4094 shift;
    nts::InputComponent strobe, data, clk, oe;

    shift.setLink(1, strobe, 1);
    shift.setLink(2, data, 1);
    shift.setLink(3, clk, 1);
    shift.setLink(15, oe, 1);

    strobe.setValue(nts::False);
    data.setValue(nts::False);
    clk.setValue(nts::False);
    oe.setValue(nts::True);

    cr_assert_eq(shift.compute(4), nts::Undefined);
}

/// @brief Verifies that a rising clock edge with strobe shifts data into the first output
Test(Advanced4094, ShiftDataIn)
{
    nts::Advanced4094 shift;
    nts::InputComponent strobe, data, clk, oe;

    shift.setLink(1, strobe, 1);
    shift.setLink(2, data, 1);
    shift.setLink(3, clk, 1);
    shift.setLink(15, oe, 1);

    oe.setValue(nts::True);
    strobe.setValue(nts::True);

    data.setValue(nts::True);
    clk.setValue(nts::False);
    shift.simulate(1);
    shift.compute(4);

    clk.setValue(nts::True);
    shift.simulate(2);
    cr_assert_eq(shift.compute(4), nts::True);
}

/// @brief Verifies that disabling output enable (OE=False) makes data outputs Undefined
Test(Advanced4094, OutputEnableOff)
{
    nts::Advanced4094 shift;
    nts::InputComponent strobe, data, clk, oe;

    shift.setLink(1, strobe, 1);
    shift.setLink(2, data, 1);
    shift.setLink(3, clk, 1);
    shift.setLink(15, oe, 1);

    strobe.setValue(nts::True);
    data.setValue(nts::True);
    clk.setValue(nts::False);
    oe.setValue(nts::False);

    cr_assert_eq(shift.compute(4), nts::Undefined);
    cr_assert_eq(shift.compute(5), nts::Undefined);
}

/// @brief Verifies that serial outputs Qs (pin 9) and Qe (pin 10) are Undefined at initialization
Test(Advanced4094, QsQeOutputs)
{
    nts::Advanced4094 shift;
    nts::InputComponent strobe, data, clk, oe;

    shift.setLink(1, strobe, 1);
    shift.setLink(2, data, 1);
    shift.setLink(3, clk, 1);
    shift.setLink(15, oe, 1);

    strobe.setValue(nts::False);
    data.setValue(nts::False);
    clk.setValue(nts::False);
    oe.setValue(nts::False);

    nts::Tristate qs = shift.compute(9);
    nts::Tristate qe = shift.compute(10);
    (void)qs;
    (void)qe;
    cr_assert_eq(shift.compute(9), nts::Undefined);
    cr_assert_eq(shift.compute(10), nts::Undefined);
}

/// @brief Verifies that selector 000 routes data channel 0 to the output
Test(Advanced4512, SelectChannel0)
{
    nts::Advanced4512 mux;
    nts::InputComponent d0, d1, d2, d3, d4, d5, d6, d7;
    nts::InputComponent selA, selB, selC, inhibit, enable;

    mux.setLink(1, d0, 1);
    mux.setLink(2, d1, 1);
    mux.setLink(3, d2, 1);
    mux.setLink(4, d3, 1);
    mux.setLink(5, d4, 1);
    mux.setLink(6, d5, 1);
    mux.setLink(7, d6, 1);
    mux.setLink(9, d7, 1);
    mux.setLink(11, selA, 1);
    mux.setLink(12, selB, 1);
    mux.setLink(13, selC, 1);
    mux.setLink(10, inhibit, 1);
    mux.setLink(15, enable, 1);

    d0.setValue(nts::True);
    d1.setValue(nts::False);
    d2.setValue(nts::False);
    d3.setValue(nts::False);
    d4.setValue(nts::False);
    d5.setValue(nts::False);
    d6.setValue(nts::False);
    d7.setValue(nts::False);

    selA.setValue(nts::False);
    selB.setValue(nts::False);
    selC.setValue(nts::False);
    inhibit.setValue(nts::False);
    enable.setValue(nts::False);

    cr_assert_eq(mux.compute(14), nts::True);
}

/// @brief Verifies that selector 101 routes data channel 5 to the output
Test(Advanced4512, SelectChannel5)
{
    nts::Advanced4512 mux;
    nts::InputComponent d0, d1, d2, d3, d4, d5, d6, d7;
    nts::InputComponent selA, selB, selC, inhibit, enable;

    mux.setLink(1, d0, 1);
    mux.setLink(2, d1, 1);
    mux.setLink(3, d2, 1);
    mux.setLink(4, d3, 1);
    mux.setLink(5, d4, 1);
    mux.setLink(6, d5, 1);
    mux.setLink(7, d6, 1);
    mux.setLink(9, d7, 1);
    mux.setLink(11, selA, 1);
    mux.setLink(12, selB, 1);
    mux.setLink(13, selC, 1);
    mux.setLink(10, inhibit, 1);
    mux.setLink(15, enable, 1);

    d0.setValue(nts::False);
    d1.setValue(nts::False);
    d2.setValue(nts::False);
    d3.setValue(nts::False);
    d4.setValue(nts::False);
    d5.setValue(nts::True);
    d6.setValue(nts::False);
    d7.setValue(nts::False);

    selA.setValue(nts::True);
    selB.setValue(nts::False);
    selC.setValue(nts::True);
    inhibit.setValue(nts::False);
    enable.setValue(nts::False);

    cr_assert_eq(mux.compute(14), nts::True);
}

/// @brief Verifies that setting enable high produces Undefined output (active-low enable)
Test(Advanced4512, EnableHigh_Undefined)
{
    nts::Advanced4512 mux;
    nts::InputComponent d0, selA, selB, selC, inhibit, enable;

    mux.setLink(1, d0, 1);
    mux.setLink(11, selA, 1);
    mux.setLink(12, selB, 1);
    mux.setLink(13, selC, 1);
    mux.setLink(10, inhibit, 1);
    mux.setLink(15, enable, 1);

    d0.setValue(nts::True);
    selA.setValue(nts::False);
    selB.setValue(nts::False);
    selC.setValue(nts::False);
    inhibit.setValue(nts::False);
    enable.setValue(nts::True);

    cr_assert_eq(mux.compute(14), nts::Undefined);
}

/// @brief Verifies that setting inhibit high forces output to False
Test(Advanced4512, InhibitHigh_False)
{
    nts::Advanced4512 mux;
    nts::InputComponent d0, selA, selB, selC, inhibit, enable;

    mux.setLink(1, d0, 1);
    mux.setLink(11, selA, 1);
    mux.setLink(12, selB, 1);
    mux.setLink(13, selC, 1);
    mux.setLink(10, inhibit, 1);
    mux.setLink(15, enable, 1);

    d0.setValue(nts::True);
    selA.setValue(nts::False);
    selB.setValue(nts::False);
    selC.setValue(nts::False);
    inhibit.setValue(nts::True);
    enable.setValue(nts::False);

    cr_assert_eq(mux.compute(14), nts::False);
}

/// @brief Verifies that an Undefined selector input propagates Undefined to the output
Test(Advanced4512, UndefinedSelector)
{
    nts::Advanced4512 mux;
    nts::InputComponent d0, selA, selB, selC, inhibit, enable;

    mux.setLink(1, d0, 1);
    mux.setLink(11, selA, 1);
    mux.setLink(12, selB, 1);
    mux.setLink(13, selC, 1);
    mux.setLink(10, inhibit, 1);
    mux.setLink(15, enable, 1);

    d0.setValue(nts::True);
    selA.setValue(nts::Undefined);
    selB.setValue(nts::False);
    selC.setValue(nts::False);
    inhibit.setValue(nts::False);
    enable.setValue(nts::False);

    cr_assert_eq(mux.compute(14), nts::Undefined);
}

/// @brief Verifies that selector 111 routes data channel 7 to the output
Test(Advanced4512, SelectChannel7)
{
    nts::Advanced4512 mux;
    nts::InputComponent d0, d1, d2, d3, d4, d5, d6, d7;
    nts::InputComponent selA, selB, selC, inhibit, enable;

    mux.setLink(1, d0, 1);
    mux.setLink(2, d1, 1);
    mux.setLink(3, d2, 1);
    mux.setLink(4, d3, 1);
    mux.setLink(5, d4, 1);
    mux.setLink(6, d5, 1);
    mux.setLink(7, d6, 1);
    mux.setLink(9, d7, 1);
    mux.setLink(11, selA, 1);
    mux.setLink(12, selB, 1);
    mux.setLink(13, selC, 1);
    mux.setLink(10, inhibit, 1);
    mux.setLink(15, enable, 1);

    d0.setValue(nts::False);
    d1.setValue(nts::False);
    d2.setValue(nts::False);
    d3.setValue(nts::False);
    d4.setValue(nts::False);
    d5.setValue(nts::False);
    d6.setValue(nts::False);
    d7.setValue(nts::True);

    selA.setValue(nts::True);
    selB.setValue(nts::True);
    selC.setValue(nts::True);
    inhibit.setValue(nts::False);
    enable.setValue(nts::False);

    cr_assert_eq(mux.compute(14), nts::True);
}

/// @brief Verifies that input 0000 activates output 0 (pin 11) and deactivates others
Test(Advanced4514, DecodeZero)
{
    nts::Advanced4514 decoder;
    nts::InputComponent strobe, a, b, c, d, inhibit;

    decoder.setLink(1, strobe, 1);
    decoder.setLink(2, a, 1);
    decoder.setLink(3, b, 1);
    decoder.setLink(21, c, 1);
    decoder.setLink(22, d, 1);
    decoder.setLink(23, inhibit, 1);

    strobe.setValue(nts::True);
    a.setValue(nts::False);
    b.setValue(nts::False);
    c.setValue(nts::False);
    d.setValue(nts::False);
    inhibit.setValue(nts::False);

    cr_assert_eq(decoder.compute(11), nts::True);
    cr_assert_eq(decoder.compute(9), nts::False);
    cr_assert_eq(decoder.compute(10), nts::False);
    cr_assert_eq(decoder.compute(8), nts::False);
}

/// @brief Verifies that input 0011 activates output 3 (pin 8) and deactivates output 0
Test(Advanced4514, DecodeThree)
{
    nts::Advanced4514 decoder;
    nts::InputComponent strobe, a, b, c, d, inhibit;

    decoder.setLink(1, strobe, 1);
    decoder.setLink(2, a, 1);
    decoder.setLink(3, b, 1);
    decoder.setLink(21, c, 1);
    decoder.setLink(22, d, 1);
    decoder.setLink(23, inhibit, 1);

    strobe.setValue(nts::True);
    a.setValue(nts::True);
    b.setValue(nts::True);
    c.setValue(nts::False);
    d.setValue(nts::False);
    inhibit.setValue(nts::False);

    cr_assert_eq(decoder.compute(8), nts::True);
    cr_assert_eq(decoder.compute(11), nts::False);
}

/// @brief Verifies that asserting inhibit forces all decoder outputs to False
Test(Advanced4514, InhibitForcesAllFalse)
{
    nts::Advanced4514 decoder;
    nts::InputComponent strobe, a, b, c, d, inhibit;

    decoder.setLink(1, strobe, 1);
    decoder.setLink(2, a, 1);
    decoder.setLink(3, b, 1);
    decoder.setLink(21, c, 1);
    decoder.setLink(22, d, 1);
    decoder.setLink(23, inhibit, 1);

    strobe.setValue(nts::True);
    a.setValue(nts::False);
    b.setValue(nts::False);
    c.setValue(nts::False);
    d.setValue(nts::False);
    inhibit.setValue(nts::True);

    cr_assert_eq(decoder.compute(11), nts::False);
    cr_assert_eq(decoder.compute(9), nts::False);
    cr_assert_eq(decoder.compute(10), nts::False);
    cr_assert_eq(decoder.compute(8), nts::False);
}

/// @brief Verifies that the decoder latches its input when strobe goes low, ignoring subsequent input changes
Test(Advanced4514, StrobeLatch)
{
    nts::Advanced4514 decoder;
    nts::InputComponent strobe, a, b, c, d, inhibit;

    decoder.setLink(1, strobe, 1);
    decoder.setLink(2, a, 1);
    decoder.setLink(3, b, 1);
    decoder.setLink(21, c, 1);
    decoder.setLink(22, d, 1);
    decoder.setLink(23, inhibit, 1);

    strobe.setValue(nts::True);
    a.setValue(nts::False);
    b.setValue(nts::False);
    c.setValue(nts::False);
    d.setValue(nts::False);
    inhibit.setValue(nts::False);
    decoder.compute(11);

    decoder.simulate(1);
    strobe.setValue(nts::False);
    a.setValue(nts::True);
    b.setValue(nts::True);
    inhibit.setValue(nts::False);

    cr_assert_eq(decoder.compute(11), nts::True);
}

/// @brief Verifies that input 0101 activates output 5 (pin 6) and deactivates output 0
Test(Advanced4514, DecodeFive)
{
    nts::Advanced4514 decoder;
    nts::InputComponent strobe, a, b, c, d, inhibit;

    decoder.setLink(1, strobe, 1);
    decoder.setLink(2, a, 1);
    decoder.setLink(3, b, 1);
    decoder.setLink(21, c, 1);
    decoder.setLink(22, d, 1);
    decoder.setLink(23, inhibit, 1);

    strobe.setValue(nts::True);
    a.setValue(nts::True);
    b.setValue(nts::False);
    c.setValue(nts::True);
    d.setValue(nts::False);
    inhibit.setValue(nts::False);

    cr_assert_eq(decoder.compute(6), nts::True);
    cr_assert_eq(decoder.compute(11), nts::False);
}

/// @brief Verifies that computing on an invalid pin number returns Undefined
Test(Advanced4514, InvalidPin)
{
    nts::Advanced4514 decoder;
    nts::InputComponent strobe, a, b, c, d, inhibit;

    decoder.setLink(1, strobe, 1);
    decoder.setLink(2, a, 1);
    decoder.setLink(3, b, 1);
    decoder.setLink(21, c, 1);
    decoder.setLink(22, d, 1);
    decoder.setLink(23, inhibit, 1);

    strobe.setValue(nts::True);
    a.setValue(nts::False);
    b.setValue(nts::False);
    c.setValue(nts::False);
    d.setValue(nts::False);
    inhibit.setValue(nts::False);

    cr_assert_eq(decoder.compute(99), nts::Undefined);
}
