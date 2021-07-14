# include <string.h>
# include <unistd.h>
# include <stdlib.h>
#include <stdio.h>
typedef struct		var
{
	int coup;
    int min;
    int max;
    int n_val;
   	struct s_list	*first;
	struct s_list	*last; 
}					t_var;

typedef struct		s_list
{
	int			content;
	int			val;
	struct s_list	*next;
	struct s_list	*prec;
}					t_list;

int sa(t_var **list)
{
	list[0]->coup++;
    t_list *temp;

    temp = list[0]->first->next;
    list[0]->first->next = temp->next;    
    list[0]->first->prec = temp;    
    temp->next = list[0]->first;
    temp->prec = NULL;
    list[0]->first = temp;
    return 0;
}

int sb(t_var **list)
{
		list[0]->coup++;

    t_list *temp;

    temp = list[1]->first->next;
    list[1]->first->next = temp->next;    
    list[1]->first->prec = temp;    
    temp->next = list[1]->first;
    temp->prec = NULL;
    list[1]->first = temp;
    return 0;
}

int ss(t_var **list)
{
    sa(list);
    sb(list);
    return 0;
}

int ra(t_var **list)
{	list[0]->coup++;

    t_list *temp;

    temp = list[0]->first;
    list[0]->first = list[0]->first->next;
    list[0]->first->prec = NULL;
    temp->next = NULL;
    list[0]->last->next = temp;
    temp->prec = list[0]->last;
    list[0]->last = temp;
    return 0;
}

int rb(t_var **list)
{	list[0]->coup++;

    t_list *temp;

    temp = list[1]->first;
    list[1]->first = list[1]->first->next;
    list[1]->first->prec = NULL;
    temp->next = NULL;
    list[1]->last->next = temp;
    temp->prec = list[1]->last;
    list[1]->last = temp;
    return 0;
}

int rr(t_var **list)
{
    ra(list);
    rb(list);
    return 0;
}


int rra(t_var **list)
{	list[0]->coup++;

    t_list *temp;

    temp = list[0]->last;
    list[0]->last = list[0]->last->prec;
    list[0]->last->next = NULL;
    temp->prec = NULL;
    temp->next = list[0]->first;
    list[0]->first = temp;
    return 0;
}


int rrb(t_var **list)
{	list[0]->coup++;

    t_list *temp;
    temp = list[1]->last;
    list[1]->last = list[1]->last->prec;

//	if (list[1]->last != NULL)
	    list[1]->last->next = NULL;

    temp->prec = NULL;
    temp->next = list[1]->first;
    list[1]->first = temp;
    return 0;
}

int rrr(t_var **list)
{
    rra(list);
    rrb(list);
    return 0;
}


int pa(t_var **list)
{
	list[0]->coup++;
	
    t_list *temp;

    temp = list[1]->first;

    list[1]->first = temp->next;
	if (list[1]->first)
		list[1]->first->prec = NULL;
	else
		list[1]->last = NULL;
	if (list[0]->first != NULL)
        list[0]->first->prec = temp;
    temp->prec = NULL;
    temp->next = list[0]->first;


    list[0]->first = temp;

    if (temp ->next == NULL)
    list[0]->last = temp;
    
	return 0;
}

int pb(t_var **list)
{
	list[0]->coup++;
	
    t_list *temp;

    temp = list[0]->first;

    list[0]->first = temp->next;
	if (list[0]->first)
		list[0]->first->prec = NULL;
	else
		list[0]->last = NULL;
	if (list[1]->first != NULL)
        list[1]->first->prec = temp;
    temp->prec = NULL;
    temp->next = list[1]->first;


    list[1]->first = temp;

    if (temp ->next == NULL)
    list[1]->last = temp;
    
	return 0;
}








static int	calc(int i, const char *str, int sign)
{
	long	result;
	int		j;

	result = 0;
	j = i;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10;
		result = result + (str[i] - '0');
		if (result > 2147483648 && sign == 1)
			return (0);
		if (result > 2147483647 && sign == 0)
			return (-1);
		i++;
	}
	return (result);
}

int			ft_atoi(const char *str)
{
	int result;
	int i;
	int sign;

	sign = 0;
	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
	{
		i++;
	}
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign++;
		i++;
	}
	if (str[i] == '+' || str[i] == '-')
		return (0);
	result = calc(i, str, sign);
	if (sign % 2 == 0)
		return (result);
	return (result * -1);
}


t_list	*ft_lstnew(int content, int *val)
{
	t_list *result;

	if (!(result = (t_list *)malloc(sizeof(t_list))))
		return (0);
	result->next = NULL;
	result->prec = NULL;
	result->content = content;

    int i = 0;
    while (val[i] != content)
        i++;
    result->val = i + 1;
	return (result);
}

void			ft_lstadd_back(t_var *list, int content, int *val)
{
	t_list *new;

    new = ft_lstnew(content, val);

	if (list->last == NULL)
		list->first = new;
    else
    	list->last->next = new;
    new->prec = list->last;
    list->last = new;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int i;
	int temp;

	i = 0;
	while (i < (size - 1))
	{
		if (tab[i] > tab[i + 1] && (i < (size - 1)))
		{
			temp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = temp;
			i = 0;
		}
		else
		{
			i++;
		}
	}
}

t_var    **create_list(int argc, char **argv)
{
    int i;

    i = 1;
    t_var **list;

	if (!(list = malloc(sizeof(t_var *) * 2)))
		return (0);
	if (!(list[0] = malloc(sizeof(t_var))))
		return (0);
    list[0]->first = NULL;
    list[0]->last = NULL;
	if (!(list[1] = malloc(sizeof(t_var))))
		return (0);
    list[1]->first = NULL;
    list[1]->last = NULL;

    int *val;
    int y = 1;

    val = malloc(sizeof(int) * argc);
    while (y < argc)
    {
        val[y - 1] = ft_atoi(argv[y]);
        y++;
    }
    ft_sort_int_tab(val, argc - 1);
    while (i < argc)
    {
        ft_lstadd_back(list[0], ft_atoi(argv[i]), val);
        i++;
    }
    return(list);
}

int min_max(t_var **list)
{
	t_list *temp;
    int i;

    i = 0;
    while (i < 2)
    {
        list[i]->n_val = 0;
        temp = list[i]->first;
        list[i]->max = -1;
        list[i]->min = -1;
        while(temp != NULL)
        {
            if (temp->val > list[i]->max)
                list[i]->max = temp->val;
            if ((temp->val < list[i]->min) || (list[i]->min == -1))
                list[i]->min = temp->val;
            list[i]->n_val++;
			list[i]->last = temp;
            temp = temp->next;
        }
        i++;
    }
    return 0;
}

int calc_score(t_var **list)
{
    int i;
    int score;
    int place;
	t_list *temp;
//printf("\n\n\n\n\n\n\n");


    score = 0;
    place = 0;
    i = 1;
    temp = list[0]->first;
    while ((i < ((list[0]->n_val / 2) + 1)) && temp != NULL)
    {
        if (((((list[0]->max - temp->val) * 2) + i) < score) || (score == 0))
        {
  //          printf("2    ");
            place = i;
            score = i + ((list[0]->max - temp->val) * 2);
        }
        if ((((temp->val - list[0]->min) * 2) + i) < score)
        {
            // printf("3    ");
            place = i;
            score = i + ((temp->val - list[0]->min) * 2);
        }
        // printf("%i  -%i-      -%i-    \n",temp->val,place, score);
        temp = temp->next;
        i++;
    }
// printf("\n\n\n");
//		printf("\ntest\n");
    i = 2;
    temp = list[0]->last;
    while ((i < ((list[0]->n_val / 2) + 1)) && temp != NULL)
    {
        if ((((((list[0]->max) - temp->val) * 2) + i) < score) || (score == 0))
        {
            place = i * -1;
            score = i + ((list[0]->max - temp->val) * 2);
        }
        if ((((temp->val - list[0]->min) * 2) + i) < score)
        {
            place = i * -1;
            score = i + ((temp->val - list[0]->min) * 2);
        }
//         printf("%i  -%i-      -%i-    \n",temp->val,place, score);
        temp = temp->prec;
        i++;
    }
// printf("\n\n\n\n\n\n\n   %i  \n\n\n",list[0]->n_val / 2);
    return place;
}














int affichage(t_var **list)
{
    t_list *test;
    t_list *test2;
    test = list[0]->first;
    test2 = list[1]->first;

        printf("num     A          B\n\n");

    int i = 1;
    while (!(test == NULL && test2 == NULL))
    {
        printf("%-2i      ", i);
        i++;
        if (test != NULL)
        {
            printf("%-3i ",test->val);
            test = test->next;
        }
        else
        {
            printf("    ");   
        }
        
        if (test2 != NULL)
        {
            printf("       %i",test2->val);
            test2 = test2->next;
        }
        printf("\n");
    }
    return 0;
}



int positionement(t_var **list, int place)
{
    printf("\nplace = %i\n\n", place);

        while (place < -1)
        {
            rra(list);
            place ++;
 //           affichage(list);
        }

        while (place > 1)
        {
            ra(list);
            place --;
//            affichage(list);
        }
        pb(list);

    if (list[1]->first->val > (((list[0]->max - list[0]->min)/2) + list[0]->min) && list[1]->first->next)
        rb(list);
    return 0;
}

int positionement_final(t_var **list, int place)
{
    printf("\nplace = %i\n\n", place);

        while (place < 0)
        {
            rrb(list);
            place ++;
 //           affichage(list);
        }

        while (place > 1)
        {
            rb(list);
            place --;
//            affichage(list);
        }
        pa(list);

//    if (list[1]->first->val > (((list[0]->max - list[0]->min)/2) + list[0]->min) && list[1]->first->next)
//        rb(list);

    return 0;
}



int 	cherche(t_var *list, int num)
{
	t_list *temp;

	temp = list->first;
	int i;
	i = 1;
	int y;
	y = 1;
	while(temp->next && temp->val != num)
	{
		i++;
		temp = temp->next;
	}
	temp = list->last;
	while(temp->prec && temp->val != num)
	{
		y ++;
		temp = temp->prec;
	}
	if (i <= y)
		return i;
	return (y * -1);
}

int main(int argc, char **argv)
{
	t_var **list;
    int place;

    list = (t_var **)create_list(argc, argv);
	list[0]->coup = 0;
	list[1]->coup = 0;
    affichage(list);
    while (list[0]->first->next != NULL)
    {
		min_max(list);
        place = calc_score(list);
        positionement(list, place);
 		affichage(list);
    }
    pb(list);
    affichage(list);
	while (list[1]->n_val > 2)
	{
		min_max(list);
		place = cherche(list[1], list[1]->max);
		positionement_final(list, place);
		affichage(list);
			printf("\n\ncoup = %i\n", list[0]->coup);

	}
    pa(list);
	affichage(list);
	printf("\n\ncoup = %i\n", list[0]->coup);
	return 0;
}
// 824 102 781 16 671 875 605 493 415 254 842 545 534 100 428 48 276 45 833 455 215 302 410 297 327 928 286 579 699 131 767 444 942 814 305 137 580 175 185 620 966 569 101 143 638 632 764 615 965 468 713 584 471 621 731 738 838 54 945 406 882 711 883 565 129 864 340 309 981 926 813 216 312 829 224 880 698 479 58 689 992 969 106 760 89 518 568 656 558 914 796 716 555 31 963 284 401 208 587 932



//547 651 779 819 502 539 289 332 447 139 715 278 995 85 619 609 730 190 770 657 823 210 712 663 845 348 209 313 288 63 931 915 113 524 274 391 834 740 692 312 932 409 702 565 406 435 865 714 107 942 984 1 800 272 297 518 176 689 175 992 67 206 981 19 978 116 719 696 543 298 438 875 762 734 633 216 642 56 848 89 199 245 167 356 773 706 983 894 20 955 576 608 166 788 833 798 813 454 317 43
//38 723 384 180 623 737 958 280 784 532 246 154 204 541 980 526 846 509 335 661 253 749 703 706 945 748 317 459 620 247 55 894 70 954 942 254 926 23 826 577 196 676 62 222 986 289 739 371 205 141 917 567 110 54 919 366 531 691 619 866 932 683 401 820 573 841 580 144 309 786 267 405 895 206 600 259 207 799 59 658 607 11 111 193 346 884 187 888 42 717 370 995 188 164 56 241 546 778 775 501

// 643 157 461 261 564 52 961 460 797 331 50 64 692 172 504 445 105 868 902 976 819 779 777 846 567 364 786 696 104 246 726 852 252 690 127 405 242 562 762 417 657 353 528 931 165 559 768 648 294 112 737 580 177 83 787 299 413 401 887 927 30 480 409 488 4 523 990 733 956 706 372 658 879 26 220 251 538 901 118 300 468 87 139 533 835 312 859 689 948 704 974 33 360 752 354 914 63 406 700 707

// 662 65 198 915 617 417 225 353 262 162 913 892 679 764 766 755 339 396 951 757 560 666 739 696 109 879 753 287 902 56 654 254 141 351 101 972 578 91 297 782 767 133 191 643 456 810 727 50 412 145 236 833 332 528 808 485 340 895 150 541 935 594 681 987 652 260 612 859 623 934 301 423 234 426 937 830 982 281 47 948 698 946 750 178 637 305 321 288 432 97 729 31 576 976 470 998 840 775 96 680 219 496 215 965 248 67 13 771 792 466 952 410 725 807 705 116 335 18 865 9 599 582 568 939 428 227 588 359 922 343 48 24 121 4 184 406 360 932 34 491 276 209 76 584 929 111 735 524 408 472 492 61 770 453 135 811 884 543 36 161 342 289 224 259 249 768 533 675 3 577 452 787 797 431 51 896 886 21 532 630 872 632 660 1000 658 501 436 122 418 887 566 243 398 798 138 479 380 228 853 174 813 277 626 715 151 692 836 991 182 375 898 851 961 84 223 849 153 860 476 772 669 959 716 818 825 23 384 397 700 665 279 127 53 969 33 440 63 399 931 761 583 647 783 645 167 425 420 850 358 441 503 405 689 691 930 690 748 315 92 586 347 26 330 633 539 414 197 334 173 514 424 14 673 355 506 743 592 70 169 275 284 322 955 226 780 723 166 515 672 862 957 856 421 745 306 247 6 609 614 379 49 258 555 348 157 909 981 171 240 616 17 468 869 336 115 549 331 81 531 78 99 600 747 309 916 341 547 589 809 72 529 131 199 461 484 404 651 958 346 526 756 751 39 364 912 522 444 413 205 789 924 201 621 415 866 707 168 416 264 970 657 480 706 497 98 189 35 474 475 449 627 177 920 207 125 352 483 940 376 401 90 967 32 300 0 66 469 919 882 713 373 59 222 826 844 107 676 605 911 944 754 385 758 839 392 148 366 805 819 806 356 73 290 802 881 11 38 518 536 634 604 327 889 256 508 585 876 128 517 41 239 535 20 394 272 55 267 570 374 235 251 294 852 429 232 395 801 164 686 516 244 611 8 966 268 640 172 712 500 973 595 160 642 784 704 682 559 463 701 550 936 846 104 117 822 644 28 803 661 598 779 571 814 211 383 434 152 12 656 493 29 220 68 901 816 863 883 760 454 907 857 793 875 847 155 871 139 893 714 180 74 124 650 606 683 829 828 710 147 299 252 985 796 242 329 308 977 495 377 964 473 845 390 202 858 238 158 664 186 693 113 196 192 512 694 677 273 544 737 843 369 885 229 318 75 433 88 43 71 855 545 868 622 742 708 193 641 736 812 313 579 670 368 928 854 635 478 194 975 119 1 732 551 210 112 786 624 325 762 354 842 827 720 403 195 477 488 79 241 482 730 538 861 265 323 914 821 303 411 540 519 521 978 597 89 286 146 190 817 448 302 213 799 163 746 22 573 19 974 908 487 906 537 357 54 834 283 838 575 678 891 457 950 607 389 702 917 962 212 156 554 136 100 925 458 295 613 422 391 927 791 386 103 345 269 10 997 292 200 655 282 69 956 667 668 204 618 646 699 486 5 625 317 629 968 214 562 261 110 2 591 489 430 900 527 954 159 510 848 880 941 567 80 738 83 899 328 728 274 873 949 897 185 921 57 788 953 504 30 393 120 44 363 619 820 58 563 960 381 778 943 719 569 905 255 874 362 765 688 7 653 777 285 615 638 795 206 558 446 179 320 601 971 523 175 996 511 427 450 718 574 45 546 620 890 938 776 763 400 695 176 867 963 181 208 298 984 804 581 659 835 785 918 382 217 711 106 149 752 114 590 326 77 505 565 144 296 266 271 333 923 118 378 443 741 154 52 520 983 316 257 894 250 781 587 188 687 525 445 631 402 221 231 338 561 870 409 230 749 85 507 841 310 459 993 731 697 87 462 499 319 132 37 467 447 800 165 490 734 995 246 105 102 945 370 933 988 311 349 451 437 721 790 367 994 216 824 60 979 270 129 464 733 42 534 126 237 992 649 877 610 27 388 904 726 552 596 94 773 837 703 942 628 709 312 494 602 108 460 203 137 864 926 580 86 509 344 293 371 910 744 278 717 187 636 387 280 794 769 365 471 64 245 134 542 15 123 419 572 831 465 671 608 442 263 823 324 888 183 439 481 663 674 740 62 438 989 593 372 455 556 759 435 903 685 815 218 93 502 170 832 684 304 639 40 557 999 140 46 513 407 25 233 143 986 947 603 990 980 648 16 130 724 553 142 350 361 548 95 307 82 498 291 530 337 253 722 564 878 774
