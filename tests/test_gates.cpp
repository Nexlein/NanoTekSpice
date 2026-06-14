/*
** EPITECH PROJECT, 2026
** G-OOP-400-MPL-4-1-tekspice-6
** File description:
** test_gates
*/

#include <criterion/criterion.h>

#include "Components/Gates/Gate4001.hpp"
#include "Components/Gates/Gate4011.hpp"
#include "Components/Gates/Gate4030.hpp"
#include "Components/Gates/Gate4069.hpp"
#include "Components/Gates/Gate4071.hpp"
#include "Components/Gates/Gate4081.hpp"
#include "Components/Special/InputComponent.hpp"

/// @brief Tests 4001 NOR gate -> only true when both inputs are false
Test(Gates, Gate4001_NOR)
{
    nts::Gate4001 gate;
    nts::InputComponent left;
    nts::InputComponent right;

    gate.setLink(1, left, 1);
    gate.setLink(2, right, 1);

    // 0 NOR 0 = 1
    left.setValue(nts::Tristate::False);
    right.setValue(nts::Tristate::False);
    cr_assert_eq(gate.compute(3), nts::Tristate::True);

    // 0 NOR 1 = 0
    gate.simulate(1);
    left.setValue(nts::Tristate::False);
    right.setValue(nts::Tristate::True);
    cr_assert_eq(gate.compute(3), nts::Tristate::False);

    // 1 NOR 0 = 0
    gate.simulate(2);
    left.setValue(nts::Tristate::True);
    right.setValue(nts::Tristate::False);
    cr_assert_eq(gate.compute(3), nts::Tristate::False);

    // 1 NOR 1 = 0
    gate.simulate(3);
    left.setValue(nts::Tristate::True);
    right.setValue(nts::Tristate::True);
    cr_assert_eq(gate.compute(3), nts::Tristate::False);
}

/// @brief Tests 4001 NOR gate with Undefined inputs
Test(Gates, Gate4001_NOR_Undefined)
{
    nts::Gate4001 gate;
    nts::InputComponent left;
    nts::InputComponent right;

    gate.setLink(1, left, 1);
    gate.setLink(2, right, 1);

    // U NOR 0 = U
    left.setValue(nts::Tristate::Undefined);
    right.setValue(nts::Tristate::False);
    cr_assert_eq(gate.compute(3), nts::Tristate::Undefined);

    // 0 NOR U = U
    gate.simulate(1);
    left.setValue(nts::Tristate::False);
    right.setValue(nts::Tristate::Undefined);
    cr_assert_eq(gate.compute(3), nts::Tristate::Undefined);

    // U NOR 1 = 0 (NOR is always 0 when any input is 1)
    gate.simulate(2);
    left.setValue(nts::Tristate::Undefined);
    right.setValue(nts::Tristate::True);
    cr_assert_eq(gate.compute(3), nts::Tristate::False);

    // 1 NOR U = 0
    gate.simulate(3);
    left.setValue(nts::Tristate::True);
    right.setValue(nts::Tristate::Undefined);
    cr_assert_eq(gate.compute(3), nts::Tristate::False);

    // U NOR U = U
    gate.simulate(4);
    left.setValue(nts::Tristate::Undefined);
    right.setValue(nts::Tristate::Undefined);
    cr_assert_eq(gate.compute(3), nts::Tristate::Undefined);
}

/// @brief Tests 4011 NAND gate -> only false when both inputs are true
Test(Gates, Gate4011_NAND)
{
    nts::Gate4011 gate;
    nts::InputComponent left;
    nts::InputComponent right;

    gate.setLink(1, left, 1);
    gate.setLink(2, right, 1);

    // 0 NAND 0 = 1
    left.setValue(nts::Tristate::False);
    right.setValue(nts::Tristate::False);
    cr_assert_eq(gate.compute(3), nts::Tristate::True);

    // 0 NAND 1 = 1
    gate.simulate(1);
    left.setValue(nts::Tristate::False);
    right.setValue(nts::Tristate::True);
    cr_assert_eq(gate.compute(3), nts::Tristate::True);

    // 1 NAND 0 = 1
    gate.simulate(2);
    left.setValue(nts::Tristate::True);
    right.setValue(nts::Tristate::False);
    cr_assert_eq(gate.compute(3), nts::Tristate::True);

    // 1 NAND 1 = 0
    gate.simulate(3);
    left.setValue(nts::Tristate::True);
    right.setValue(nts::Tristate::True);
    cr_assert_eq(gate.compute(3), nts::Tristate::False);
}

/// @brief Tests 4011 NAND gate with Undefined inputs
Test(Gates, Gate4011_NAND_Undefined)
{
    nts::Gate4011 gate;
    nts::InputComponent left;
    nts::InputComponent right;

    gate.setLink(1, left, 1);
    gate.setLink(2, right, 1);

    // U NAND 1 = U
    left.setValue(nts::Tristate::Undefined);
    right.setValue(nts::Tristate::True);
    cr_assert_eq(gate.compute(3), nts::Tristate::Undefined);

    // 1 NAND U = U
    gate.simulate(1);
    left.setValue(nts::Tristate::True);
    right.setValue(nts::Tristate::Undefined);
    cr_assert_eq(gate.compute(3), nts::Tristate::Undefined);

    // U NAND 0 = 1
    gate.simulate(2);
    left.setValue(nts::Tristate::Undefined);
    right.setValue(nts::Tristate::False);
    cr_assert_eq(gate.compute(3), nts::Tristate::True);

    // 0 NAND U = 1
    gate.simulate(3);
    left.setValue(nts::Tristate::False);
    right.setValue(nts::Tristate::Undefined);
    cr_assert_eq(gate.compute(3), nts::Tristate::True);

    // U NAND U = U
    gate.simulate(4);
    left.setValue(nts::Tristate::Undefined);
    right.setValue(nts::Tristate::Undefined);
    cr_assert_eq(gate.compute(3), nts::Tristate::Undefined);
}

/// @brief Tests 4030 XOR gate -> true when inputs are different, false when
/// same
Test(Gates, Gate4030_XOR)
{
    nts::Gate4030 gate;
    nts::InputComponent left;
    nts::InputComponent right;

    gate.setLink(1, left, 1);
    gate.setLink(2, right, 1);

    // 0 XOR 0 = 0
    left.setValue(nts::Tristate::False);
    right.setValue(nts::Tristate::False);
    cr_assert_eq(gate.compute(3), nts::Tristate::False);

    // 0 XOR 1 = 1
    gate.simulate(1);
    left.setValue(nts::Tristate::True);
    right.setValue(nts::Tristate::False);
    cr_assert_eq(gate.compute(3), nts::Tristate::True);

    // 1 XOR 0 = 1
    gate.simulate(2);
    left.setValue(nts::Tristate::False);
    right.setValue(nts::Tristate::True);
    cr_assert_eq(gate.compute(3), nts::Tristate::True);

    // 1 XOR 1 = 0
    gate.simulate(3);
    left.setValue(nts::Tristate::True);
    right.setValue(nts::Tristate::True);
    cr_assert_eq(gate.compute(3), nts::Tristate::False);
}

/// @brief Tests 4030 XOR gate with Undefined inputs
Test(Gates, Gate4030_XOR_Undefined)
{
    nts::Gate4030 gate;
    nts::InputComponent left;
    nts::InputComponent right;

    gate.setLink(1, left, 1);
    gate.setLink(2, right, 1);

    // U XOR 0 = U
    left.setValue(nts::Tristate::Undefined);
    right.setValue(nts::Tristate::False);
    cr_assert_eq(gate.compute(3), nts::Tristate::Undefined);

    // 0 XOR U = U
    gate.simulate(1);
    left.setValue(nts::Tristate::False);
    right.setValue(nts::Tristate::Undefined);
    cr_assert_eq(gate.compute(3), nts::Tristate::Undefined);

    // U XOR 1 = U
    gate.simulate(2);
    left.setValue(nts::Tristate::Undefined);
    right.setValue(nts::Tristate::True);
    cr_assert_eq(gate.compute(3), nts::Tristate::Undefined);

    // 1 XOR U = U
    gate.simulate(3);
    left.setValue(nts::Tristate::True);
    right.setValue(nts::Tristate::Undefined);
    cr_assert_eq(gate.compute(3), nts::Tristate::Undefined);

    // U XOR U = U
    gate.simulate(4);
    left.setValue(nts::Tristate::Undefined);
    right.setValue(nts::Tristate::Undefined);
    cr_assert_eq(gate.compute(3), nts::Tristate::Undefined);
}

/// @brief Tests 4069 NOT gate -> output is inverse of input for each pair of
/// pins
Test(Gates, Gate4069_NOT)
{
    nts::Gate4069 gate;
    nts::InputComponent in;

    // Pin 1→2
    gate.setLink(1, in, 1);
    // 0 → 1
    in.setValue(nts::Tristate::False);
    cr_assert_eq(gate.compute(2), nts::Tristate::True);
    // 1 → 0
    in.setValue(nts::Tristate::True);
    cr_assert_eq(gate.compute(2), nts::Tristate::False);

    // Pin 3→4
    gate.setLink(3, in, 1);
    // 0 → 1
    in.setValue(nts::Tristate::False);
    cr_assert_eq(gate.compute(4), nts::Tristate::True);
    // 1 → 0
    in.setValue(nts::Tristate::True);
    cr_assert_eq(gate.compute(4), nts::Tristate::False);

    // Pin 5→6
    gate.setLink(5, in, 1);
    // 0 → 1
    in.setValue(nts::Tristate::False);
    cr_assert_eq(gate.compute(6), nts::Tristate::True);
    // 1 → 0
    in.setValue(nts::Tristate::True);
    cr_assert_eq(gate.compute(6), nts::Tristate::False);

    // Pin 9→8
    gate.setLink(9, in, 1);
    // 0 → 1
    in.setValue(nts::Tristate::False);
    cr_assert_eq(gate.compute(8), nts::Tristate::True);
    // 1 → 0
    in.setValue(nts::Tristate::True);
    cr_assert_eq(gate.compute(8), nts::Tristate::False);

    // Pin 11→10
    gate.setLink(11, in, 1);
    // 0 → 1
    in.setValue(nts::Tristate::False);
    cr_assert_eq(gate.compute(10), nts::Tristate::True);
    // 1 → 0
    in.setValue(nts::Tristate::True);
    cr_assert_eq(gate.compute(10), nts::Tristate::False);

    // Pin 13→12
    gate.setLink(13, in, 1);
    // 0 → 1
    in.setValue(nts::Tristate::False);
    cr_assert_eq(gate.compute(12), nts::Tristate::True);
    // 1 → 0
    in.setValue(nts::Tristate::True);
    cr_assert_eq(gate.compute(12), nts::Tristate::False);
}

/// @brief Tests 4069 NOT gate with Undefined input
Test(Gates, Gate4069_NOT_Undefined)
{
    nts::Gate4069 gate;
    nts::InputComponent in;

    gate.setLink(1, in, 1);

    // NOT U = U
    in.setValue(nts::Tristate::Undefined);
    cr_assert_eq(gate.compute(2), nts::Tristate::Undefined);
}

/// @brief Tests 4071 OR gate -> only false when both inputs are false
Test(Gates, Gate4071_OR)
{
    nts::Gate4071 gate;
    nts::InputComponent left;
    nts::InputComponent right;

    gate.setLink(1, left, 1);
    gate.setLink(2, right, 1);

    // 0 OR 0 = 0
    left.setValue(nts::Tristate::False);
    right.setValue(nts::Tristate::False);
    cr_assert_eq(gate.compute(3), nts::Tristate::False);

    // 0 OR 1 = 1
    gate.simulate(1);
    left.setValue(nts::Tristate::True);
    right.setValue(nts::Tristate::False);
    cr_assert_eq(gate.compute(3), nts::Tristate::True);

    // 1 OR 0 = 1
    gate.simulate(2);
    left.setValue(nts::Tristate::False);
    right.setValue(nts::Tristate::True);
    cr_assert_eq(gate.compute(3), nts::Tristate::True);

    // 1 OR 1 = 1
    gate.simulate(3);
    left.setValue(nts::Tristate::True);
    right.setValue(nts::Tristate::True);
    cr_assert_eq(gate.compute(3), nts::Tristate::True);
}

/// @brief Tests 4071 OR gate with Undefined inputs
Test(Gates, Gate4071_OR_Undefined)
{
    nts::Gate4071 gate;
    nts::InputComponent left;
    nts::InputComponent right;

    gate.setLink(1, left, 1);
    gate.setLink(2, right, 1);

    // U OR 0 = U
    left.setValue(nts::Tristate::Undefined);
    right.setValue(nts::Tristate::False);
    cr_assert_eq(gate.compute(3), nts::Tristate::Undefined);

    // 0 OR U = U
    gate.simulate(1);
    left.setValue(nts::Tristate::False);
    right.setValue(nts::Tristate::Undefined);
    cr_assert_eq(gate.compute(3), nts::Tristate::Undefined);

    // U OR 1 = 1
    gate.simulate(2);
    left.setValue(nts::Tristate::Undefined);
    right.setValue(nts::Tristate::True);
    cr_assert_eq(gate.compute(3), nts::Tristate::True);

    // 1 OR U = 1
    gate.simulate(3);
    left.setValue(nts::Tristate::True);
    right.setValue(nts::Tristate::Undefined);
    cr_assert_eq(gate.compute(3), nts::Tristate::True);

    // U OR U = U
    gate.simulate(4);
    left.setValue(nts::Tristate::Undefined);
    right.setValue(nts::Tristate::Undefined);
    cr_assert_eq(gate.compute(3), nts::Tristate::Undefined);
}

/// @brief Tests 4081 AND gate -> only true when both inputs are true
Test(Gates, Gate4081_AND)
{
    nts::Gate4081 gate;
    nts::InputComponent left;
    nts::InputComponent right;

    gate.setLink(1, left, 1);
    gate.setLink(2, right, 1);

    // 0 AND 0 = 0
    left.setValue(nts::Tristate::False);
    right.setValue(nts::Tristate::False);
    cr_assert_eq(gate.compute(3), nts::Tristate::False);

    // 0 AND 1 = 0
    gate.simulate(1);
    left.setValue(nts::Tristate::True);
    right.setValue(nts::Tristate::False);
    cr_assert_eq(gate.compute(3), nts::Tristate::False);

    // 1 AND 0 = 0
    gate.simulate(2);
    left.setValue(nts::Tristate::False);
    right.setValue(nts::Tristate::True);
    cr_assert_eq(gate.compute(3), nts::Tristate::False);

    // 1 AND 1 = 1
    gate.simulate(3);
    left.setValue(nts::Tristate::True);
    right.setValue(nts::Tristate::True);
    cr_assert_eq(gate.compute(3), nts::Tristate::True);
}

/// @brief Tests 4081 AND gate with Undefined inputs
Test(Gates, Gate4081_AND_Undefined)
{
    nts::Gate4081 gate;
    nts::InputComponent left;
    nts::InputComponent right;

    gate.setLink(1, left, 1);
    gate.setLink(2, right, 1);

    // U AND 1 = U
    left.setValue(nts::Tristate::Undefined);
    right.setValue(nts::Tristate::True);
    cr_assert_eq(gate.compute(3), nts::Tristate::Undefined);

    // 1 AND U = U
    gate.simulate(1);
    left.setValue(nts::Tristate::True);
    right.setValue(nts::Tristate::Undefined);
    cr_assert_eq(gate.compute(3), nts::Tristate::Undefined);

    // U AND 0 = 0
    gate.simulate(2);
    left.setValue(nts::Tristate::Undefined);
    right.setValue(nts::Tristate::False);
    cr_assert_eq(gate.compute(3), nts::Tristate::False);

    // 0 AND U = 0
    gate.simulate(3);
    left.setValue(nts::Tristate::False);
    right.setValue(nts::Tristate::Undefined);
    cr_assert_eq(gate.compute(3), nts::Tristate::False);

    // U AND U = U
    gate.simulate(4);
    left.setValue(nts::Tristate::Undefined);
    right.setValue(nts::Tristate::Undefined);
    cr_assert_eq(gate.compute(3), nts::Tristate::Undefined);
}
