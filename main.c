/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 16:53:07 by lpan              #+#    #+#             */
/*   Updated: 2018/12/12 16:54:21 by lpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"
#include <stdarg.h>
#include <stdio.h>

int main()
{
	signed int i = 21474;
	signed short sho = 32767;
	signed char c = 'c';
 	char *str = "Hello World";
	signed long l = 2147483647;
	signed long long ll = -9223372036854775807;

	unsigned int u = 65535;
	unsigned short usho = 65535;
	unsigned char z = 'z';
	unsigned long ul = 4294967295;
	unsigned long long ull = 18446744073709551615;
	double f = 999.99998475; //double has 15 decimal digits of precision.
	long double ld = 42.1234567890123456789012345;

	ft_printf("special test: \n");
	printf("re_printf: %\n");
	ft_printf("ft_printf: %\n");
	printf("re_printf: % m\n");
	ft_printf("ft_printf: % m\n");
	printf("re_printf: % .5m\n");
	ft_printf("ft_printf: % .5m\n");
	printf("%.0%\n");
	ft_printf("%.0%\n");
	printf("%%\n");
	ft_printf("%%\n");
	printf("%m is this work\n");
	ft_printf("%m is this work\n");
	printf("re_printf: %05bcd\n", "test");
	ft_printf("ft_printf: %05bcd\n", "test");
	printf("re_printf: %5%\n");
	ft_printf("ft_printf: %5%\n");
	printf("re_printf: %%\n");
	ft_printf("ft_printf: %%\n");
	printf("re_printf: %   %\n", "test");
	ft_printf("ft_printf: %   %\n", "test");
	printf("re_printf:%-5ct\n", c);
	ft_printf("ft_printf:%-5ct\n", c);
	printf("re_printf: %s %\n", "test");
	ft_printf("ft_printf: %s %\n", "test");
	printf("%.*d\n", -15, 0);
	ft_printf("%.*d\n", -15, 0);
	printf("%*d\n", 5, 42);
	ft_printf("%*d\n", 5, 42);
	ft_printf("\n");

	ft_printf("f: \n");
	printf("re_printf: 10.15f: %010.15f\n", f);
	ft_printf("ft_printf: 10.15f: %010.15f\n", f);

	printf("re_printf: 10.2f: %010.2f\n", 4.999);
	ft_printf("ft_printf: 10.2f: %010.2f\n", 4.999);
	printf("re_printf: 010.4f: %010.4f\n", f);
	ft_printf("ft_printf: 010.4f: %010.4f\n", f);
	printf("re_printf: +10.4f: %+10.4f\n", f);
	ft_printf("ft_printf: +10.4f: %+10.4f\n", f);
	printf("re_printf: +10.30Lf: %+10.30Lf\n", ld);
	ft_printf("ft_printf: +10.30Lf: %+10.30Lf\n", ld);
	printf("re_printf: +10.300Lf: %+10.300Lf\n", ld);
	ft_printf("ft_printf: +10.300Lf: %+10.300Lf\n", ld);
	printf("re_printf: +10.300f: %+10.300f\n", 0.1999);
	ft_printf("ft_printf: +10.300f: %+10.300f\n", 0.1999);
	printf("re_printf: +10.300f: %+10.300f\n", 0.0009);
	ft_printf("ft_printf: +10.300f: %+10.300f\n", 0.0009);
	printf("%05f\n", f);
	ft_printf("%05f\n", f);
	printf("re_printf: % f\n", f);
	ft_printf("ft_printf: % f\n", f);
	printf("re_printf: % .2f\n", f);
	ft_printf("ft_printf: % .2f\n", f);
	printf("%3f\n", f);
	ft_printf("%3f\n", f);
	printf("re_printf: 0+5f: %0+5f\n", f);
	ft_printf("ft_printf: 0+5f: %0+5f\n", f);
	printf("re_printf:010.1f: %010.1f\n",f);//
	ft_printf("ft_printf:010.1f: %010.1f\n", f);//
	printf("re_printf: +.f: % +.f\n", f);//
	ft_printf("ft_printf: +.f: % +.f\n", f);//
	printf("re_printf:0-f: %0-f\n", f);
	ft_printf("ft_printf:0-f: %0-f\n", f);
	printf("re_printf:+ 6.6f: %+ 6.6f\n", f);
	ft_printf("ft_printf:+ 6.6f: %+ 6.6f\n", f);
	printf("re_printf:+010.7f: %+010.7f\n", f);
	ft_printf("ft_printf:+010.7f: %+010.7f\n", f);
	printf("re_printf:+ 10.7f: %+ 10.7f\n", f);
	ft_printf("ft_printf:+ 10.7f: %+ 10.7f\n", f);
	printf("re_printf:-010.7f: %-010.7f\n", f);
	ft_printf("ft_printf:-010.7f: %-010.7f\n", f);
	printf("re_printf:- 10.7f: %- 10.7f\n", f);
	ft_printf("ft_printf:- 10.7f: %- 10.7f\n", f);
	printf("re_printf:-010.7f: %-010.7f\n", -f);
	ft_printf("ft_printf:-010.7f: %-010.7f\n", -f);
	printf("re_printf: +10.30Lf: %+10.30Lf\n", ld);
	ft_printf("ft_printf: +10.30Lf: %+10.30Lf\n", ld);
	printf("re_printf: +10.300Lf: %+10.300Lf\n", ld);
	ft_printf("ft_printf: +10.300Lf: %+10.300Lf\n", ld);
		printf("re_printf: 10.3f: %010.3f\n", -4.99);
		ft_printf("ft_printf: 10.3f: %010.3f\n", -4.99);
		printf("re_printf: 10.f: %0+10.f\n", -4.55);
		ft_printf("ft_printf: 10.f: %0+10.f\n", -4.55);
		printf("re_printf: 10f: %0+10f\n", -4.55);
		ft_printf("ft_printf: 10f: %0+10f\n", -4.55);
		printf("re_printf: 10.0f: %0+10.0f\n", -4.99);
		ft_printf("ft_printf: 10.0f: %0+10.0f\n", -4.99);
		printf("re_printf: 10.2f: %010.2f\n", 1.453443);
		ft_printf("ft_printf: 10.2f: %010.2f\n", 1.453443);
		printf("re_printf: 10.15f: %010.15f\n", f);
		ft_printf("ft_printf: 10.15f: %010.15f\n", f);
		printf("re_printf: 10.15f: %010.15f\n", f);
		ft_printf("ft_printf: 10.15f: %010.15f\n", f);
		printf("re_printf:010.1f: %010.1f\n",f);//
		ft_printf("ft_printf:010.1f: %010.1f\n", f);//
		printf("re_printf: +.f: % +.f\n", f);//
		ft_printf("ft_printf: +.f: % +.f\n", f);//
		printf("re_printf: 10.15f: %010.15f\n", 0.00);//
		ft_printf("ft_printf: 10.15f: %010.15f\n", 0.00);//
		printf("re_printf: 10.15f: %010.15f\n", 0);//
		ft_printf("ft_printf: 10.15f: %010.15f\n", 0);//
ft_printf("\n");

	ft_printf("c: \n");
	printf("re_printf:%05c\n", c);
	ft_printf("ft_printf:%05c\n", c);
	ft_printf("\n");

	ft_printf("s: \n");
	printf("re_printf: %4.s\n", "42");
	ft_printf("ft_printf: %4.s\n", "42");
	printf("re_printf:% 30.3s\n", str);
	ft_printf("ft_printf:% 30.3s\n", str);
	printf("re_printf: %saaa%sbbb%sccc\n", "AAA", "BBB", "CCC");
	ft_printf("ft_printf: %saaa%sbbb%sccc\n", "AAA", "BBB", "CCC");
	printf("re_printf: %s\n", NULL);
	ft_printf("ft_printf: %s\n", NULL);
	printf("%05.s\n", 0);
	ft_printf("%05.s\n", 0);
	printf("%-.2s is a string\n", "this");
	ft_printf("%-.2s is a string\n", "this");
	printf("re_printf:% -.3s\n", str);
	ft_printf("ft_printf:% -.3s\n", str);
	printf("%-10s is a string\n", "this");
	ft_printf("%-10s is a string\n", "this");
	ft_printf("\n");

	ft_printf("d&i: \n");
	printf("%0-3d\n", 0);
	ft_printf("%0-3d\n", 0);
	printf("%+03d\n", 0);
	ft_printf("%+03d\n", 0);
	printf("%+03d\n", 0);
	ft_printf("%+03d\n", 0);
	printf("% 04d\n", 0);
	ft_printf("% 04d\n", 0);
	printf("re_printf: %5.0d\n", 0);
	ft_printf("ft_printf: %5.0d\n", 0);
	printf("re_printf: %5.d %5.0d\n", 0, 0);
	ft_printf("ft_printf: %5.d %5.0d\n", 0, 0);
	printf("%05d\n", -42);
	ft_printf("%05d\n", -42);
	printf("re_printf: % d\n", -42);
	ft_printf("ft_printf: % d\n", -42);
	printf("re_printf: % d\n", 42);
	ft_printf("ft_printf: % d\n", 42);
	printf("%3d\n", -42);
	ft_printf("%3d\n", -42);
	printf("re_printf: 0+5d: %0+5d\n", 42);
	ft_printf("ft_printf: 0+5d: %0+5d\n", 42);
	printf("re_printf:010d: %010d\n",42);
	ft_printf("ft_printf:010d: %010d\n", 42);
	printf("re_printf: +d: % +d\n", 42);
	ft_printf("ft_printf: +d: % +d\n", 42);
	printf("re_printf:0-d: %0-d\n", 42);
	ft_printf("ft_printf:0-d: %0-d\n", 42);
	printf("re_printf:010d: %010d\n",i);
	ft_printf("ft_printf:010d: %010d\n", i);
	printf("re_printf:+ 6.6d: %+ 6.6d\n", i);
	ft_printf("ft_printf:+ 6.6d: %+ 6.6d\n", i);
	printf("re_printf:+010.7d: %+010.7d\n", i);
	ft_printf("ft_printf:+010.7d: %+010.7d\n", i);
	printf("re_printf:+ 10.7d: %+ 10.7d\n", i);
	ft_printf("ft_printf:+ 10.7d: %+ 10.7d\n", i);
	printf("re_printf:-010.7d: %-010.7d\n", i);
	ft_printf("ft_printf:-010.7d: %-010.7d\n", i);
	printf("re_printf:- 10.7d: %- 10.7d\n", i);
	ft_printf("ft_printf:- 10.7d: %- 10.7d\n", i);
	printf("re_printf:-010.7d: %-010.7d\n", -i);
	ft_printf("ft_printf:-010.7d: %-010.7d\n", -i);
	printf("re_printf:7.8d: %7.8d\n", i);
	ft_printf("ft_printf:7.8d: %7.8d\n", i);
	printf("re_printf:+6.6d: %+6.6d\n", i);
	ft_printf("ft_printf:+6.6d: %+6.6d\n", i);
	printf("re_printf: 6.6hd: % 6.6hd\n", sho);
	ft_printf("ft_printf: 6.6hd: % 6.6hd\n", sho);
	printf("re_printf:5.7hhd: %5.7hhd\n", c);
	ft_printf("ft_printf:5.7hhd: %5.7hhd\n", c);
	printf("re_printf:8.7ld: %8.7ld\n", l);
	ft_printf("ft_printf:8.7ld: %8.7ld\n", l);
	printf("re_printf:+010.7lld: %+010.lld\n", ll);
	ft_printf("ft_printf:+010.7lld: %+010.7lld\n", ll);
	printf("%lld\n", 9223372036854775808);
	ft_printf("%lld\n", 9223372036854775808);
	printf("%lld\n", -9223372036854775808);
	ft_printf("%lld\n", -9223372036854775808);
	printf("%jd\n", -9223372036854775809);
	ft_printf("%jd\n", -9223372036854775809);
	ft_printf("\n");

	ft_printf("u: \n");
	printf("re_printf: %u\n", -1);
	ft_printf("ft_printf: %u\n", -1);
	printf("re_printf: %u\n", 4294967295);
	ft_printf("ft_printf: %u\n", 4294967295);
	printf("re_printf: %hu\n", 4294967296);
	ft_printf("ft_printf: %hu\n", 4294967296);
	printf("re_printf: %5.0u\n", 0);
	ft_printf("ft_printf: %5.0u\n", 0);
	printf("re_printf:+6.6u: %+6.6u\n", u);
	ft_printf("ft_printf:+6.6u: %+6.6u\n", u);
	printf("re_printf: 6.6hu: % 6.6hu\n", usho);
	ft_printf("ft_printf: 6.6hu: % 6.6hu\n", usho);
	printf("re_printf:5.7hhu: %5.7hhu\n", z);
	ft_printf("ft_printf:5.7hhu: %5.7hhu\n", z);
	printf("re_printf:8.7lu: %8.7lu\n", ul);
	ft_printf("ft_printf:8.7lu: %8.7lu\n", ul);
	printf("re_printf:+010.7llu: %+010.llu\n", ull);
	ft_printf("ft_printf:+010.7llu: %+010.7llu\n", ull);
	ft_printf("\n");

	ft_printf("o: \n");
	printf("re_printf: %#.o %#.0o\n", 0, 0);
	ft_printf("ft_printf: %#.o %#.0o\n", 0, 0);
	printf("re_printf: %.o %.0o\n", 0, 0);
	ft_printf("ft_printf: %.o %.0o\n", 0, 0);
	printf("re_printf:+ 6.6o: %+ 6.6o\n", i);
	ft_printf("ft_printf:+ 6.6o: %+ 6.6o\n", i);
	printf("re_printf:+015.12o: %+015.12o\n", i);
	ft_printf("ft_printf:+015.12o: %+015.12o\n", i);
	printf("re_printf:+ 10.7o: %+ 10.7o\n", i);
	ft_printf("ft_printf:+ 10.7o: %+ 10.7o\n", i);
	printf("re_printf:-010.7o: %-010.7o\n", i);
	ft_printf("ft_printf:-010.7o: %-010.7o\n", i);
	printf("re_printf:- #15.12o: %- #15.12o\n", i);
	ft_printf("ft_printf:- #15.12o: %- #15.12o\n", i);
	printf("re_printf:7.8o: %7.8o\n", i);
	ft_printf("ft_printf:7.8o: %7.8o\n", i);
	printf("re_printf:+#6.5o: %+#6.5o\n", i);
	ft_printf("ft_printf:+#6.5o: %+#6.5o\n", i);
	printf("re_printf: 6.6ho: % 6.6ho\n", sho);
	ft_printf("ft_printf: 6.6ho: % 6.6ho\n", sho);
	printf("re_printf:5.7hho: %5.7hho\n", c);
	ft_printf("ft_printf:5.7hho: %5.7hho\n", c);
	printf("re_printf:8.7lo: %8.7lo\n", l);
	ft_printf("ft_printf:8.7lo: %8.7lo\n", l);
	printf("re_printf:+010.7llo: %+010.llo\n", ll);
	ft_printf("ft_printf:+010.7llo: %+010.7llo\n", ll);
	ft_printf("\n");

	ft_printf("x: \n");
		printf("re_printf: -42x: %x\n", -42);
		ft_printf("ft_printf: -42x: %x\n", -42);
	printf("re_printf: %#.x %#.0x\n", 0, 0);
	ft_printf("ft_printf: %#.x %#.0x\n", 0, 0);
	printf("re_printf: %#x\n", 0);
	ft_printf("ft_printf: %#x\n", 0);
	printf("re_printf:+ 6.6x: %+ 6.6x\n", i);
	ft_printf("ft_printf:+ 6.6x: %+ 6.6x\n", i);
	printf("re_printf:+#015.12x: %+#015.12x\n", i);
	ft_printf("ft_printf:+#015.12x: %+#015.12x\n", i);
	printf("re_printf:+ 10.7x: %+ 10.7x\n", i);
	ft_printf("ft_printf:+ 10.7x: %+ 10.7x\n", i);
	printf("re_printf:-010.7x: %-010.7x\n", i);
	ft_printf("ft_printf:-010.7x: %-010.7x\n", i);
	printf("re_printf:- 15.12x: %- 15.12x\n", i);
	ft_printf("ft_printf:- 15.12x: %- 15.12x\n", i);
	printf("re_printf:#7.8x: %#7.8x\n", i);
	ft_printf("ft_printf:#7.8x: %#7.8x\n", i);
	printf("re_printf:+6.6x: %+6.6x\n", i);
	ft_printf("ft_printf:+6.6x: %+6.6x\n", i);
	printf("re_printf: 6.6hx: % 6.6hx\n", sho);
	ft_printf("ft_printf: 6.6hx: % 6.6hx\n", sho);
	printf("re_printf:5.7hhx: %5.7hhx\n", c);
	ft_printf("ft_printf:5.7hhx: %5.7hhx\n", c);
	printf("re_printf:8.7lx: %8.7lx\n", l);
	ft_printf("ft_printf:8.7lx: %8.7lx\n", l);
	printf("re_printf:+010.7llx: %+010.llx\n", ll);
	ft_printf("ft_printf:+010.7llx: %+010.7llx\n", ll);
	printf("re_printf: %010x\n", i);
	ft_printf("ft_printf: %010x\n", i);
	printf("re_printf:#08x: %#08x\n", i);
	ft_printf("ft_printf:#08x: %#08x\n", i);
	printf("re_printf:#015.12x: %#015.12x\n", i);
	ft_printf("ft_printf:#015.12x: %#015.12x\n", i);
	printf("re_printf:#15x: %#15x\n", i);
	ft_printf("ft_printf:#15x: %#15x\n", i);
	printf("re_printf:#015x: %#015x\n", i);
	ft_printf("ft_printf:#015x: %#015x\n", i);
	printf("re_printf:#015.3x: %#015.3x\n", i);
	ft_printf("ft_printf:#015.3x: %#015.3x\n", i);
	printf("re_printf: %#.x %#.0x\n", 0, 0);
	ft_printf("ft_printf: %#.x %#.0x\n", 0, 0);
	printf("re_printf: %05x\n", 0);
	ft_printf("ft_printf: %05x\n", 0);
 printf("re_printf: %05.x\n", 0);
 ft_printf("ft_printf: %05.x\n", 0);
 printf("re_printf: %x\n", 0);
 ft_printf("ft_printf: %x\n", 0);
 printf("re_printf: %#.0x\n", 0);
 ft_printf("ft_printf: %#.0x\n", 0);
 printf("re_printf: %.x\n", 0);
 ft_printf("ft_printf: %.x\n", 0);
	ft_printf("\n");

	ft_printf("X: \n");
	printf("re_printf:+ 6.6X: %+ 6.6X\n", i);
	ft_printf("ft_printf:+ 6.6X: %+ 6.6X\n", i);
	printf("re_printf:+015.12X: %+015.12X\n", i);
	ft_printf("ft_printf:+015.12X: %+015.12X\n", i);
	printf("re_printf:+ 10.7X: %+ 10.7X\n", i);
	ft_printf("ft_printf:+ 10.7X: %+ 10.7X\n", i);
	printf("re_printf:-#010.7X: %-#010.7X\n", i);
	ft_printf("ft_printf:-#010.7X: %-#010.7X\n", i);
	printf("re_printf:- 15.12X: %- 15.12X\n", i);
	ft_printf("ft_printf:- 15.12X: %- 15.12X\n", i);
	printf("re_printf:7.8X: %7.8X\n", i);
	ft_printf("ft_printf:7.8X: %7.8X\n", i);
	printf("re_printf:+#6.6X: %+#6.6X\n", i);
	ft_printf("ft_printf:+#6.6X: %+#6.6X\n", i);
	printf("re_printf: 6.6hX: % 6.6hX\n", sho);
	ft_printf("ft_printf: 6.6hX: % 6.6hX\n", sho);
	printf("re_printf:5.7hhX: %5.7hhX\n", c);
	ft_printf("ft_printf:5.7hhX: %5.7hhX\n", c);
	printf("re_printf:8.7lX: %8.7lX\n", l);
	ft_printf("ft_printf:8.7lX: %8.7lX\n", l);
	printf("re_printf:+010.7llX: %+010.llX\n", ll);
	ft_printf("ft_printf:+010.7llX: %+010.7llX\n", ll);
	ft_printf("\n");

	ft_printf("p: \n");
	printf("%p\n", 0);
	ft_printf("%p\n", 0);
	printf("%.0p, %.p\n", 0, 0);
	ft_printf("%.0p, %.p\n", 0, 0);
	printf("%0p, %.p\n", 0, 4);
	ft_printf("%0p, %.p\n", 0, 4);
	printf ("p: pointer address: %p \n", str);
	ft_printf ("p: pointer address: %p \n", str);
	printf("re_printf:+ 6.6p: %+ 6.6p\n", str);
	ft_printf("ft_printf:+ 6.6p: %+ 6.6p\n", str);
	printf("re_printf:+015.12p: %+015.12p\n", str);
	ft_printf("ft_printf:+015.12p: %+015.12p\n", str);
	printf("re_printf:+ 10.7p: %+ 10.7p\n", str);
	ft_printf("ft_printf:+ 10.7p: %+ 10.7p\n", str);
	printf("re_printf:-010.7p: %-010.7p\n", str);
	ft_printf("ft_printf:-010.7p: %-010.7p\n", str);
	printf("re_printf:- 15.12p: %- 15.12p\n", str);
	ft_printf("ft_printf:- 15.12p: %- 15.12p\n", str);
	printf("re_printf:7.8p: %7.8p\n", str);
	ft_printf("ft_printf:7.8p: %7.8p\n", str);
	printf("re_printf:+6.6p: %+6.6p\n", str);
	ft_printf("ft_printf:+6.6p: %+6.6p\n", str);
	printf("re_printf: 6.6hp: % 6.6hp\n", sho);
	ft_printf("ft_printf: 6.6hp: % 6.6hp\n", sho);
	printf("re_printf:5.7hhp: %5.7hhp\n", c);
	ft_printf("ft_printf:5.7hhp: %5.7hhp\n", c);
	printf("re_printf:8.7lp: %8.7lp\n", l);
	ft_printf("ft_printf:8.7lp: %8.7lp\n", l);
	printf("re_printf:+010.7llp: %+010.llp\n", ll);
	ft_printf("ft_printf:+010.7llp: %+010.7llp\n", ll);
	ft_printf("\n");

/*
	printf ("d&i: Signed decimal integer: %d  %i\n", 42, -42);// [−32,767, +32,767]
	printf ("o: Unsigned octal: %o \n", 42);
	printf ("u: Unsigned decimal integer: %u \n", 42);// [0, 65,535]
	printf ("x & X: Unsigned hexadecimal integer: %x %X \n", 42, 42);

	printf ("f: Decimal floating point: %f\n", 42.1234567890123456789);

	printf ("\nflags:\n");
	printf ("-: Left-justify within the given field width: %-5c \n", 'a');
	printf ("+: Forces the result with a plus or minus sign: %+d \n", 42);
	printf ("space: If no sign, a blank space before the value: % d \n", -42);
	printf ("space: If no sign, a blank space before the value: % d \n", 42);
	printf ("#: with o/x/X value is preceeded with 0, 0x or 0X: %#o %#x %#X\n", 42, 42, 42);
	printf ("#: with f it forces output to contain a decimal point: %#f\n", 42.12);
	printf ("0: Left-pads the number with zeroes instead of spaces: %05d \n", 42);

	printf ("\nwidth:\n");
	printf ("numeber: For integer(diouxX): blank spaces: d: %5d\n", 42);
	printf ("numeber: For float: f: %5f\n", 42.12);

	printf ("\n.precis:\n");
	printf (".numeber: For integer(diouxX): zeroes: %.5d\n", 42);
	printf (".numeber: For float: f: %.5f\n", 42.12);//same with whidth/numeber

	printf ("\nlength sub-specifier: hh h l ll L:\n");
	printf ("hh: d&i: Signed char: %hhd  %hhi\n", 'c', 'z'); //[−127, +127]
	printf ("hh: o&u&x&X: Unsigned char: %hho %hhu %hhx %hhX\n", 'c', 'a', 'z', 'g'); //[0, 255]
	printf ("h: d&i: short int: %hd  %hi\n", 127, -128); //[−32,767, +32,767]
	printf ("h: o&u&x&X: Unsigned short int: %ho %hu %hx %hX\n",  234, 234, 234, 234); //[0, 65,535]
	printf ("ll: d&i: long int: %lld  %lli\n", 127, -128); //[−9,223,372,036,854,775,807, +9,223,372,036,854,775,807]
	printf ("ll: o&u&x&X: Unsigned long int: %llo %llu %llx %llX\n",  234, 234, 234, 234); // [0, +18,446,744,073,709,551,615]
	printf ("l: d&i: long int: %ld  %li\n", 127, -128);// [−2,147,483,647, +2,147,483,647]
	printf ("l: o&u&x&X: Unsigned long int: %lo %lu %lx %lX\n",  234, 234, 234, 234); // [0, 4,294,967,295]
	printf ("l: f: double: %lf\n", 42.1234567890123456789);
	printf ("L: f: long double: %Lf\n", 42.1234567890123456789);
*/
	return (0);
}
