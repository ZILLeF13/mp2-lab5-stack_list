#define _SILENCE_TR1_NAMESPACE_DEPRECATION_WARNING
#include "../list_stack/stack.h"
#include "gtest.h"

// ASSERT_NO_THROW(TBitField bf(3)); не выкидывает исключение 
// EXPECT_EQ(3, bf.GetLength()); РАВНЫЕ
//EXPECT_NE(0, bf.GetBit(3));
//ASSERT_ANY_THROW(TBitField bf(-3)); выкидвывает исключение 

TEST(stack, ne_vikidivaet_throw)
{
  ASSERT_NO_THROW(Stack<int> bf);
}

TEST(stack, PRIRAVNIVAET_RAVNOGO_RAZMERA)
{
	Stack<int> bf;
	bf.Push(1);
	Stack<int> bf1;
	bf1.Push(3);
	bf = bf1;
	EXPECT_EQ(bf.Top(), bf1.Top());
}

TEST(stack, PRIRAVNIVAET_RAZNOGO_RAZMERA)
{
	Stack<int> bf;
	bf.Push(1);
	bf.Push(2);
	Stack<int> bf1;
	bf1.Push(3);
	bf = bf1;
	EXPECT_EQ(bf.Top(), bf1.Top());
}

TEST(stack, pokazivaet_stack_pystoi)
{
	Stack<int> bf;
	EXPECT_EQ(bf.Empty(), 1);
}

TEST(stack, kladet_znachenie_v_stack)
{
	Stack<int> bf;
		bf.Push(1);
	EXPECT_EQ(bf.Top(), 1);
}

TEST(stack, ybiraet_znachenie_iz_stack)
{
	Stack<int> bf;
	bf.Push(1);
	int i = bf.Pop();
	ASSERT_ANY_THROW(bf.Top());
}

TEST(stack, nelzia_vziat_znachenie_iz_pystogo_stack)
{
	Stack<int> bf;
	ASSERT_ANY_THROW(bf.Pop());
}

TEST(stack, sravnenie_s_ravnimi_znacheniymi_stack)
{
	Stack<int> bf;
	bf.Push(1);
	Stack<int> bf1;
	bf1.Push(1);
	int n1,n2;
	EXPECT_EQ((n1 = bf.Pop()) == (n2 = bf1.Pop()), 1);
}

TEST(stack, sravnenie_s_raznimi_znacheniymi_stack)
{
	Stack<int> bf;
	bf.Push(1);
	Stack<int> bf1;
	bf1.Push(2);
	int n1, n2;
	EXPECT_NE((n1 = bf.Pop()) == (n2 = bf1.Pop()), 1);
}

TEST(stack, 1_sravnenie_s_ravnimi_znacheniymi_stack)
{
	Stack<int> bf;
	bf.Push(1);
	Stack<int> bf1;
	bf1.Push(1);
	int n1, n2;
	EXPECT_NE((n1 = bf.Pop()) != (n2 = bf1.Pop()), 1);
}

TEST(stack, 1_sravnenie_s_raznimi_znacheniymi_stack)
{
	Stack<int> bf;
	bf.Push(1);
	Stack<int> bf1;
	bf1.Push(2);
	int n1, n2;
	EXPECT_EQ((n1 = bf.Pop()) != (n2 = bf1.Pop()), 1);
}