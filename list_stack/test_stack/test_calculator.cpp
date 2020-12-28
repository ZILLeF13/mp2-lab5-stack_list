#define _SILENCE_TR1_NAMESPACE_DEPRECATION_WARNING
#include "../list_stack/calculator.h"
#include "../list_stack/calculator.cpp"
#include "gtest.h"

// ASSERT_NO_THROW(TBitField bf(3)); не выкидывает исключение 
// EXPECT_EQ(3, bf.GetLength()); РАВНЫЕ
//EXPECT_NE(0, bf.GetBit(3));
//ASSERT_ANY_THROW(TBitField bf(-3)); выкидвывает исключение 

TEST(calculator, ne_vikidivaet_throw)
{
	ASSERT_NO_THROW(TCalculator calc);
}

TEST(calculator, prinimaet_znachenie)
{
	TCalculator calc;
	ASSERT_NO_THROW(calc.SetExpression("2+2"));
}

TEST(calculator, sozdaet_pravilniy_infix)
{
	TCalculator calc;
	calc.SetExpression("1+(1+3)*5/4");
	EXPECT_EQ("1+(1+3)*5/4", calc.GetExpression());
}

TEST(calculator, sozdaet_pravilniy_postfix)
{
	TCalculator calc;
	calc.SetExpression("1+(1+3)*5/4");
	calc.ToPostfix();
	EXPECT_EQ("1 1 3+ 5 *4/+", calc.GetPostfix());
}

TEST(calculator, skobki_rasstavleni_pravilno)
{
	TCalculator calc;
	calc.SetExpression("(1+((1+3)*5)+1)/4");
	EXPECT_EQ(1, calc.CheckBrackets());
}

TEST(calculator, slozenie_int)
{
	TCalculator calc;
	calc.SetExpression("2+2");
	calc.ToPostfix();
	double res = calc.CalcPostfix();
	EXPECT_EQ(4, res);
}

TEST(calculator, vichitanie_int)
{
	TCalculator calc;
	calc.SetExpression("1-2");
	calc.ToPostfix();
	double res = calc.CalcPostfix();
	EXPECT_EQ(-1, res);
}

TEST(calculator, ymnogenir_int)
{
	TCalculator calc;
	calc.SetExpression("3*2");
	calc.ToPostfix();
	double res = calc.CalcPostfix();
	EXPECT_EQ(6, res);
}

TEST(calculator, delenie_int)
{
	TCalculator calc;
	calc.SetExpression("4/2");
	calc.ToPostfix();
	double res = calc.CalcPostfix();
	EXPECT_EQ(2, res);
}

TEST(calculator, clozenie_double_and_int)
{
	TCalculator calc;
	calc.SetExpression("1.4+2.5+5");
	calc.ToPostfix();
	double res = calc.CalcPostfix();
	EXPECT_EQ(8.9, res);
}

TEST(calculator, vichitanie_double_and_int)
{
	TCalculator calc;
	calc.SetExpression("1.4-2.3-5");
	calc.ToPostfix();
	double res = calc.CalcPostfix();
	EXPECT_EQ(-5.9, res);
}

TEST(calculator, ymnogenie_double_and_int)
{
	TCalculator calc;
	calc.SetExpression("3.2*1");
	calc.ToPostfix();
	double res = calc.CalcPostfix();
	EXPECT_EQ(3.2, res);
}

TEST(calculator, delenie_double_and_int)
{
	TCalculator calc;
    calc.SetExpression("4.4/2/2.2");
	calc.ToPostfix();
	double res = calc.CalcPostfix();
	EXPECT_EQ(1, res);
}

TEST(calculator, summa_and_vichitanie_double_and_int)
{
	TCalculator calc;
	calc.SetExpression("1+2.2-1.1");
	calc.ToPostfix();
	double res = calc.CalcPostfix();
	EXPECT_EQ(2.1, res);
}

TEST(calculator, ymnogenie_and_delenie_double_and_int)
{
	TCalculator calc;
	calc.SetExpression("2*2.2/4.4");
	calc.ToPostfix();
	double res = calc.CalcPostfix();
	EXPECT_EQ(1, res);
}

TEST(calculator, slogenie_and_ymnogenie_and_delenie_double_and_int)
{
	TCalculator calc;
	calc.SetExpression("2*3+2*2.2/4.4");
	calc.ToPostfix();
	double res = calc.CalcPostfix();
	EXPECT_EQ(7, res);
}

TEST(calculator, vichitanie_and_ymnogenie_and_delenie_double_and_int)
{
	TCalculator calc;
	calc.SetExpression("2*3-2*2.2/4.4");
	calc.ToPostfix();
	double res = calc.CalcPostfix();
	EXPECT_EQ(5, res);
}

TEST(calculator, clogenie_and_vichitanie_and_ymnogenie_and_delenie_double_and_int)
{
	TCalculator calc;
	calc.SetExpression("2*3-2*2.2/4.4+5*6/30");
	calc.ToPostfix();
	double res = calc.CalcPostfix();
	EXPECT_EQ(6, res);
}

TEST(calculator, skobki_and_clogenie_and_vichitanie_and_ymnogenie_and_delenie_double_and_int)
{
	TCalculator calc;
	calc.SetExpression("2*3-2*2.2/4.4+5*6/30+(((7+6)*2)-2)/0.5");
	calc.ToPostfix();
	double res = calc.CalcPostfix();
	EXPECT_EQ(54, res);
}