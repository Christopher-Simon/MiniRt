/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hsl_tx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 00:38:04 by sloquet           #+#    #+#             */
/*   Updated: 2022/11/18 19:19:33 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HSL_TX_H
# define HSL_TX_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
# include <fcntl.h>
# include "../str/hsl_str.h"
# include "../file/hsl_file.h"
# include "../mem/hsl_mem.h"

# define TX_VERBOSE		0
# define TX_COLOR		1

/******************************************************************************
 **                        CUSTOMIZABLE PATTERNS RULES
 *****************************************************************************/
# define TX_SEPARATOR	':'
# define TX_SPACE		'\''
# define TX_COMMA		','
# define TX_FLOAT		'f'
# define TX_INTEGER		'i'
# define TX_POSITIVE	'+'
# define TX_RANGE_OPEN	'['
# define TX_RANGE_SEP	','
# define TX_RANGE_CLOSE	']'
# define TX_FILE		">f"
# define TX_FILE_SEP	'"'
# define TX_CHOICE		'|'

# define TX_SPACE_SET	" \t"

# define TX_FRONT_ZERO	TX_FAIL

/******************************************************************************
 **                         DO NOT MODIFY THIS SECTION
 *****************************************************************************/
# define TX_OK		0
# define TX_FAIL	1
# define TX_MALLOC	-1

# define TX_AVAL	"value"
# define TX_AMIN	"min"
# define TX_AMAX	"max"

/******************************************************************************
 **                           CUSTOMIZABLE PATTERNS
 *****************************************************************************/
# define TX_PATTERN_EXAMPLE		":A:\
'':f[0,1]:\
'':i[0,255]:,:i[0,255]:,:i[0,255]:\
'':|checker_on|checker_off|:\
'':>f:'':>f:\
"

/******************************************************************************
 **                               FUNCTIONS
 *****************************************************************************/

typedef long long	t_llong;
typedef long double	t_longd;

char	**tx_get_file(char *pathname, char *extension);

int		tx_line_match_pattern(char *input, char *pattern, int k);

void	tx_test(char *input, char *pattern, int index_line);

bool	tx_choice(int *i, char *input, char *p);
bool	tx_comma(int *i, char *input, char *p);
bool	tx_file(int *i, char *input, char *p);
bool	tx_float(int *i, char *input, char *p);
bool	tx_integer(int *i, char *input, char *p);
bool	tx_space(int *i, char *input, char *p);
bool	tx_word(int *i, char *input, char *p);

double	tx_atof(const char *str, const char *msg);
t_longd	tx_atold(const char *str, const char *msg);
int		tx_atoi(const char *str, const char *msg);
t_llong	tx_atoll(const char *str, const char *msg);
bool	tx_float_overflow(int *i, char *input);
bool	tx_integer_overflow(int *i, char *input);
char	**tx_split(const char *s, char c);

// 		tx_tools.c
char	*tx_strchr(const char *s, int c);
bool	tx_notin_range(double value, double min, double max);
int		tx_isdigit(int c);
bool	tx_digit_or_sign(int *i, char *input);
bool	tx_strict_digit(int *i, char *input);

//		tx_logs.c
void	tx_log(const char *msg);
void	tx_logv(const char *msg, bool value);
bool	tx_logr(const char *msg, bool value);
void	tx_log_invalid_symbol(int i, char *input, int k);

#endif /* HSL_TX_H */
