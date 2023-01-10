/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 22:17:29 by kodpe             #+#    #+#             */
/*   Updated: 2022/11/14 01:16:08 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

// # define LOG	printf("%s:%d %s()\n", __FILE__,__LINE__, __FUNCTION__);
# define DEBUG	1
// # define PAUSE	if (DEBUG) {getchar();};

# include "src/box/hsl_box.h"

# include "src/char/hsl_char.h"

# include "src/color/hsl_color.h"

# include "src/conv/hsl_conv.h"

// # include "src/debug/hsl_debug.h"

# include "src/file/hsl_file.h"

# include "src/hash/hsl_hash.h"

# include "src/io/hsl_io.h"

# include "src/lst/hsl_lst.h"

# include "src/maths/hsl_maths.h"

# include "src/mem/hsl_mem.h"

# include "src/sort/hsl_sort.h"

# include "src/stack/hsl_stack.h"

# include "src/str/hsl_str.h"

# include "src/tab/hsl_tab.h"

# include "src/test/hsl_test.h"

# include "src/txlib/hsl_tx.h"

# include "src/write/hsl_write.h"

#endif /* LIBFT_H */
