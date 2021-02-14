/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 10:28:39 by fde-capu          #+#    #+#             */
/*   Updated: 2021/02/13 23:19:43 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		quotes(int q)
{
	quotes_load_p1(q);
	quotes_load_p2(q);
	quotes_load_p3(q);
	quotes_load_p4(q);
	quotes_load_p5(q);
	quotes_load_p6(q);
	quotes_load_p7(q);
	quotes_load_p8(q);
	quotes_load_p9(q);
	return ;
}

void		quotes_load_p1(int q)
{
	if (q == 0)
		quote("Zero", "zero");
	if (q == 1)
		quote("One", "one");
	if (q == 2)
		quote("I do not think there is any thrill that can go through the \
human heart like that felt by the inventor as he sees some \
creation of the brain unfolding to success... Such emotions make a \
man forget food, sleep, friends, love, everything.", "Nikola Tesla");
	if (q == 3)
		quote("It was about three o’clock at night when the final result of \
the calculation [which gave birth to quantum mechanics] lay before \
me ... At first I was deeply shaken ... I was so excited that I \
could not think of sleep. So I left the house ... and awaited the \
sunrise on top of a rock.", "Werner Heisenberg");
	if (q == 4)
		quote("Men who are unhappy, like men who sleep badly, are always proud \
of the fact.", "Bertrand Russell");
	return ;
}

void		quotes_load_p2(int q)
{
	if (q == 5)
		quote("There is nothing frightening about an eternal dreamless sleep. \
Surely it is better than eternal torment in Hell and eternal \
boredom in Heaven.", "Isaac Asimov");
	if (q == 6)
		quote("We remember our dreams; we do not remember our \
sleep.", "Marguerite Yourcenar");
	if (q == 7)
		quote("What would life be without art? Science prolongs life. To \
consist of what—eating, drinking, and sleeping? What is the good \
of living longer if it is only a matter of satisfying the \
requirements that sustain life? All this is nothing without the \
charm of art.", "Sarah Bernhardt");
	if (q == 8)
		quote("In science it often happens that scientists say, 'You know \
that's a really good argument; my position is mistaken,' and then \
they would actually change their minds and you never hear that old \
view from them again. They really do it. It doesn't happen as \
often as it should, because scientists are human and change is \
sometimes painful. But it happens every day. I cannot recall the \
last time something like that happened in politics or \
religion.", "Carl Sagan");
	return ;
}

void		quotes_load_p3(int q)
{
	if (q == 9)
		quote("No small art is it to sleep: it is necessary for that purpose \
to keep awake all day. Ten times a day must thou overcome thyself: \
that causeth wholesome weariness, and is poppy to the soul. Ten times \
must thou reconcile again with thyself; for overcoming is bitterness, \
and badly sleep the unreconciled. Ten truths must thou find during the \
day; otherwise wilt thou seek truth during the night, and thy soul \
will have been hungry.", "Friedrich Nietzsche");
	if (q == 10)
		quote("We are such stuff / As dreams are made on, and our little \
life / Is rounded with a sleep.", "William Shakespeare");
	if (q == 11)
		quote("Even a soul submerged in sleep is hard at work and helps make \
something of the world.", "Heraclitus");
	if (q == 12)
		quote("Sleeping people are so remote.... Right here, but out of \
communication. That's what strikes humans as uncanny about sleep. \
Its utter privacy. The sleeper turns his back on \
everyone.", "Ursula Le Guin");
	if (q == 13)
		quote("Each day is a little life: every waking and rising a little \
birth, every fresh morning a little youth, every going to rest and \
sleep a little death.", "Arthur Schopenhauer");
	return ;
}

void		quotes_load_p4(int q)
{
	if (q == 14)
		quote("That we are not much sicker and much madder than we are is due \
exclusively to that most blessed and blessing of all natural \
graces, sleep.", "Aldous Huxley");
	if (q == 15)
		quote("Man is a genius when he is dreaming.", "Akira Kurosawa");
	if (q == 16)
		quote("Sleep is the best meditation.", "Dalai Lama");
	if (q == 17)
		quote("Think in the morning. Act in the noon. Eat in the evening. \
		Sleep in the night.", "William Blake");
	if (q == 18)
		quote("Never memorize something that you can look up.", "Albert \
Einstein");
	if (q == 19)
		quote("The good thing about science is that it's true whether or not \
you believe in it.", "Neil deGrasse Tyson");
	if (q == 20)
		quote("One, remember to look up at the stars and not down at your \
feet. Two, never give up work. Work gives you meaning and purpose \
and life is empty without it. Three, if you are lucky enough to \
find love, remember it is there and don't throw it away.", "Stephen \
Hawking");
	return ;
}
