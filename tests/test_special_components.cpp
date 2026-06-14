/*
** EPITECH PROJECT, 2026
** G-OOP-400-MPL-4-1-tekspice-6
** File description:
** test_special_components
*/

#include <criterion/criterion.h>

#include "Components/Special/ClockComponent.hpp"
#include "Components/Special/FalseComponent.hpp"
#include "Components/Special/InputComponent.hpp"
#include "Components/Special/OutputComponent.hpp"
#include "Components/Special/TrueComponent.hpp"

/// @brief Tests TrueComponent -> always True
Test(Special, TrueComponent)
{
    nts::TrueComponent trueComponent;
    cr_assert_eq(trueComponent.compute(1), nts::Tristate::True);
}

/// @brief Tests FalseComponent -> always False
Test(Special, FalseComponent)
{
    nts::FalseComponent falseComponent;
    cr_assert_eq(falseComponent.compute(1), nts::Tristate::False);
}

/// @brief Tests InputComponent setValue method
Test(Special, InputComponent_SetValue)
{
    nts::InputComponent input;

    input.setValue(nts::Tristate::True);
    cr_assert_eq(input.compute(1), nts::Tristate::True);

    input.setValue(nts::Tristate::False);
    cr_assert_eq(input.compute(1), nts::Tristate::False);

    input.setValue(nts::Tristate::Undefined);
    cr_assert_eq(input.compute(1), nts::Tristate::Undefined);
}

/// @brief Tests InputComponent simulate method -> value = nextValue
Test(Special, InputComponent_Simulate)
{
    nts::InputComponent input;

    input.setValue(nts::Tristate::False);
    input.setNextValue(nts::Tristate::True);
    input.simulate(1);
    cr_assert_eq(input.compute(1), nts::Tristate::True);
}

/// @brief Tests ClockComponent toggles value on each simulate call
Test(Special, ClockComponent_MultipleToggles)
{
    nts::ClockComponent clock;

    clock.setValue(nts::Tristate::False);
    cr_assert_eq(clock.compute(1), nts::Tristate::False);

    clock.simulate(1);
    cr_assert_eq(clock.compute(1), nts::Tristate::True);

    clock.simulate(2);
    cr_assert_eq(clock.compute(1), nts::Tristate::False);

    clock.simulate(3);
    cr_assert_eq(clock.compute(1), nts::Tristate::True);

    clock.simulate(4);
    cr_assert_eq(clock.compute(1), nts::Tristate::False);
}

/// @brief Tests OutputComponent default value is Undefined
Test(Special, OutputComponent_DefaultValue)
{
    nts::OutputComponent output;

    cr_assert_eq(output.compute(1), nts::Tristate::Undefined);
}

/// @brief Tests OutputComponent compute with invalid pin returns Undefined
Test(Special, OutputComponent_InvalidPin)
{
    nts::OutputComponent output;

    cr_assert_eq(output.compute(2), nts::Tristate::Undefined);
    cr_assert_eq(output.compute(0), nts::Tristate::Undefined);
}

/// @brief Tests OutputComponent follows linked input value
Test(Special, OutputComponent_FollowsInput)
{
    nts::OutputComponent output;
    nts::InputComponent input;

    output.setLink(1, input, 1);

    input.setValue(nts::Tristate::Undefined);
    cr_assert_eq(output.compute(1), nts::Tristate::Undefined);

    input.setValue(nts::Tristate::True);
    cr_assert_eq(output.compute(1), nts::Tristate::True);

    input.setValue(nts::Tristate::False);
    cr_assert_eq(output.compute(1), nts::Tristate::False);
}

/// @brief Basic wire, direct link true to output: TRUE ---> OUTPUT
Test(Special, OutputComponent_ImmediateTrueLink)
{
    nts::OutputComponent output;
    nts::TrueComponent trueComp;

    output.setLink(1, trueComp, 1);
    cr_assert_eq(output.getValue(), nts::Tristate::True);
}

/// @brief Basic wire, direct link false to output: FALSE ---> OUTPUT
Test(Special, OutputComponent_ImmediateFalseLink)
{
    nts::OutputComponent output;
    nts::FalseComponent falseComp;

    output.setLink(1, falseComp, 1);
    cr_assert_eq(output.getValue(), nts::Tristate::False);
}
