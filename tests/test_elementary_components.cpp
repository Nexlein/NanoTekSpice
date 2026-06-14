/*
** EPITECH PROJECT, 2026
** G-OOP-400-MPL-4-1-tekspice-6
** File description:
** test_elementary_components
*/

#include <criterion/criterion.h>

#include "Components/Elementary/AndComponent.hpp"
#include "Components/Elementary/NotComponent.hpp"
#include "Components/Elementary/OrComponent.hpp"
#include "Components/Elementary/XorComponent.hpp"
#include "Components/Special/InputComponent.hpp"

/// @brief Tests AndComponent with all combinations of True and False inputs
Test(Elementary, AndComponent)
{
    nts::AndComponent gate;
    nts::InputComponent left;
    nts::InputComponent right;

    gate.setLink(1, left, 1);
    gate.setLink(2, right, 1);

    // 0 AND 0 = 0
    left.setValue(nts::Tristate::False);
    right.setValue(nts::Tristate::False);
    cr_assert_eq(gate.compute(3), nts::Tristate::False);

    // 0 AND 1 = 0
    left.setValue(nts::Tristate::False);
    right.setValue(nts::Tristate::True);
    cr_assert_eq(gate.compute(3), nts::Tristate::False);

    // 1 AND 0 = 0
    left.setValue(nts::Tristate::True);
    right.setValue(nts::Tristate::False);
    cr_assert_eq(gate.compute(3), nts::Tristate::False);

    // 1 AND 1 = 1
    left.setValue(nts::Tristate::True);
    right.setValue(nts::Tristate::True);
    cr_assert_eq(gate.compute(3), nts::Tristate::True);

    // U AND 0 = 0
    left.setValue(nts::Tristate::True);
    right.setValue(nts::Tristate::Undefined);
    cr_assert_eq(gate.compute(3), nts::Tristate::Undefined);
}

/// @brief Tests AndComponent with undefined inputs
Test(Elementary, AndComponent_Undefined)
{
    nts::AndComponent gate;
    nts::InputComponent left;
    nts::InputComponent right;

    gate.setLink(1, left, 1);
    gate.setLink(2, right, 1);

    // U AND 0 = 0
    left.setValue(nts::Tristate::Undefined);
    right.setValue(nts::Tristate::False);
    cr_assert_eq(gate.compute(3), nts::Tristate::False);

    // U AND 1 = U
    left.setValue(nts::Tristate::Undefined);
    right.setValue(nts::Tristate::True);
    cr_assert_eq(gate.compute(3), nts::Tristate::Undefined);

    // 0 AND U = 0
    left.setValue(nts::Tristate::False);
    right.setValue(nts::Tristate::Undefined);
    cr_assert_eq(gate.compute(3), nts::Tristate::False);

    // 1 AND U = U
    left.setValue(nts::Tristate::Undefined);
    right.setValue(nts::Tristate::True);
    cr_assert_eq(gate.compute(3), nts::Tristate::Undefined);

    // U AND U = U
    left.setValue(nts::Tristate::Undefined);
    right.setValue(nts::Tristate::Undefined);
    cr_assert_eq(gate.compute(3), nts::Tristate::Undefined);
}

/// @brief Tests OrComponent with all combinations of True and False inputs
Test(Elementary, OrComponent)
{
    nts::OrComponent gate;
    nts::InputComponent left;
    nts::InputComponent right;

    gate.setLink(1, left, 1);
    gate.setLink(2, right, 1);

    // 0 OR 0 = 0
    left.setValue(nts::Tristate::False);
    right.setValue(nts::Tristate::False);
    cr_assert_eq(gate.compute(3), nts::Tristate::False);

    // 0 OR 1 = 1
    left.setValue(nts::Tristate::False);
    right.setValue(nts::Tristate::True);
    cr_assert_eq(gate.compute(3), nts::Tristate::True);

    // 1 OR 0 = 1
    left.setValue(nts::Tristate::True);
    right.setValue(nts::Tristate::False);
    cr_assert_eq(gate.compute(3), nts::Tristate::True);

    // 1 OR 1 = 1
    left.setValue(nts::Tristate::True);
    right.setValue(nts::Tristate::True);
    cr_assert_eq(gate.compute(3), nts::Tristate::True);
}

/// @brief Tests OrComponent with undefined inputs
Test(Elementary, OrComponent_Undefined)
{
    nts::OrComponent gate;
    nts::InputComponent left;
    nts::InputComponent right;

    gate.setLink(1, left, 1);
    gate.setLink(2, right, 1);

    // 0 OR U = U
    left.setValue(nts::Tristate::False);
    right.setValue(nts::Tristate::Undefined);
    cr_assert_eq(gate.compute(3), nts::Tristate::Undefined);

    // 1 OR U = 1
    left.setValue(nts::Tristate::True);
    right.setValue(nts::Tristate::Undefined);
    cr_assert_eq(gate.compute(3), nts::Tristate::True);

    // U OR 0 = U
    left.setValue(nts::Tristate::Undefined);
    right.setValue(nts::Tristate::False);
    cr_assert_eq(gate.compute(3), nts::Tristate::Undefined);

    // U OR 1 = 1
    left.setValue(nts::Tristate::Undefined);
    right.setValue(nts::Tristate::True);
    cr_assert_eq(gate.compute(3), nts::Tristate::True);

    // U OR U = U
    left.setValue(nts::Tristate::Undefined);
    right.setValue(nts::Tristate::Undefined);
    cr_assert_eq(gate.compute(3), nts::Tristate::Undefined);
}

/// @brief Tests NotComponent with all combinations of True and False inputs
Test(Elementary, XorComponent)
{
    nts::XorComponent gate;
    nts::InputComponent left;
    nts::InputComponent right;

    gate.setLink(1, left, 1);
    gate.setLink(2, right, 1);

    // 0 XOR 0 = 0
    left.setValue(nts::Tristate::False);
    right.setValue(nts::Tristate::False);
    cr_assert_eq(gate.compute(3), nts::Tristate::False);

    // 0 XOR 1 = 1
    left.setValue(nts::Tristate::True);
    right.setValue(nts::Tristate::False);
    cr_assert_eq(gate.compute(3), nts::Tristate::True);

    // 1 XOR 0 = 1
    left.setValue(nts::Tristate::False);
    right.setValue(nts::Tristate::True);
    cr_assert_eq(gate.compute(3), nts::Tristate::True);

    // 1 XOR 1 = 0
    left.setValue(nts::Tristate::True);
    right.setValue(nts::Tristate::True);
    cr_assert_eq(gate.compute(3), nts::Tristate::False);
}

/// @brief Tests NotComponent with undefined inputs
Test(Elementary, XorComponent_Undefined)
{
    nts::XorComponent gate;
    nts::InputComponent left;
    nts::InputComponent right;

    gate.setLink(1, left, 1);
    gate.setLink(2, right, 1);

    // 0 XOR U = U
    left.setValue(nts::Tristate::False);
    right.setValue(nts::Tristate::Undefined);
    cr_assert_eq(gate.compute(3), nts::Tristate::Undefined);

    // 1 XOR U = U
    left.setValue(nts::Tristate::True);
    right.setValue(nts::Tristate::Undefined);
    cr_assert_eq(gate.compute(3), nts::Tristate::Undefined);

    // U XOR 0 = U
    left.setValue(nts::Tristate::Undefined);
    right.setValue(nts::Tristate::False);
    cr_assert_eq(gate.compute(3), nts::Tristate::Undefined);

    // U XOR 1 = U
    left.setValue(nts::Tristate::Undefined);
    right.setValue(nts::Tristate::True);
    cr_assert_eq(gate.compute(3), nts::Tristate::Undefined);

    // U XOR U = U
    left.setValue(nts::Tristate::Undefined);
    right.setValue(nts::Tristate::Undefined);
    cr_assert_eq(gate.compute(3), nts::Tristate::Undefined);
}

/// @brief Tests NotComponent with all combinations of True and False and Undefined inputs
Test(Elementary, NotComponent)
{
    nts::NotComponent gate;
    nts::InputComponent left;

    gate.setLink(1, left, 1);

    // NOT 0 = 1
    left.setValue(nts::Tristate::False);
    cr_assert_eq(gate.compute(2), nts::Tristate::True);

    // NOT 1 = 0
    left.setValue(nts::Tristate::True);
    cr_assert_eq(gate.compute(2), nts::Tristate::False);

    // NOT U = U
    left.setValue(nts::Tristate::Undefined);
    cr_assert_eq(gate.compute(2), nts::Tristate::Undefined);
}
