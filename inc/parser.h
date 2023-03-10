/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 03:46:01 by sloquet           #+#    #+#             */
/*   Updated: 2022/11/22 14:50:14 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

/******************************************************************************
 **                           			GRAMMAR
 **	TX_SEPARATOR	:
 **	TX_SPACE		''
 **	TX_COMMA		,
 **	TX_FLOAT		f
 **	TX_INTEGER		i
 **	TX_POSITIVE		+
 **	TX_RANGE_OPEN	[
 **	TX_RANGE_SEP	,
 **	TX_RANGE_CLOSE	]
 **
 ** TX_SPACE_SET	" \t"
 *****************************************************************************/

/******************************************************************************
 **                           CUSTOMIZABLE PATTERNS
 *****************************************************************************/
# define TX_PATTERN_AMBIENT		":A:\
'':f[0,1]:\
'':i[0,255]:,:i[0,255]:,:i[0,255]:\
"

# define TX_PATTERN_CAMERA		":C:\
'':f[]:,:f[]:,:f[]:\
'':f[-1,1]:,:f[-1,1]:,:f[-1,1]:\
'':i[0,180]:\
"

# define TX_PATTERN_LIGHT		":L:\
'':f[]:,:f[]:,:f[]:\
'':f[0,1]:\
'':i[0,255]:,:i[0,255]:,:i[0,255]:\
"

# if BONUS == 0

#  define TX_PATTERN_PLANE		":pl:\
'':f[]:,:f[]:,:f[]:\
'':f[-1,1]:,:f[-1,1]:,:f[-1,1]:\
'':i[0,255]:,:i[0,255]:,:i[0,255]:\
"

#  define TX_PATTERN_SPHERE		":sp:\
'':f[]:,:f[]:,:f[]:\
'':f[+]:\
'':i[0,255]:,:i[0,255]:,:i[0,255]:\
"

#  define TX_PATTERN_CYLINDER	":cy:\
'':f[]:,:f[]:,:f[]:\
'':f[-1,1]:,:f[-1,1]:,:f[-1,1]:\
'':f[+]:\
'':f[+]:\
'':i[0,255]:,:i[0,255]:,:i[0,255]:\
"

#  define TX_PATTERN_CONE		0
#  define TX_PATTERN_ELLIPSOID	0
#  define TX_PATTERN_CUBOID		0

# endif

# if BONUS == 1

#  define TX_PATTERN_PLANE		":pl:\
'':f[]:,:f[]:,:f[]:\
'':f[-1,1]:,:f[-1,1]:,:f[-1,1]:\
'':i[0,255]:,:i[0,255]:,:i[0,255]:\
'':f[0,1]:'':f[0,1]:'':f[10,200]:\
'':|checker_on|checker_off|:\
"

#  define TX_PATTERN_SPHERE		":sp:\
'':f[]:,:f[]:,:f[]:\
'':f[+]:\
'':i[0,255]:,:i[0,255]:,:i[0,255]:\
'':f[0,1]:'':f[0,1]:'':f[10,200]:\
'':|checker_on|checker_off|:\
'':>f:'':>f:\
'':|skybox_on|skybox_off|:\
"

#  define TX_PATTERN_CYLINDER	":cy:\
'':f[]:,:f[]:,:f[]:\
'':f[-1,1]:,:f[-1,1]:,:f[-1,1]:\
'':f[+]:\
'':f[+]:\
'':i[0,255]:,:i[0,255]:,:i[0,255]:\
'':f[0,1]:'':f[0,1]:'':f[10,200]:\
'':|checker_on|checker_off|:\
"
#  define TX_PATTERN_CONE		":co:\
'':f[]:,:f[]:,:f[]:\
'':f[-1,1]:,:f[-1,1]:,:f[-1,1]:\
'':f[+]:\
'':i[0,255]:,:i[0,255]:,:i[0,255]:\
'':f[0,1]:'':f[0,1]:'':f[10,200]:\
'':|checker_on|checker_off|:\
'':>f:'':>f:\
"

#  define TX_PATTERN_ELLIPSOID	":el:\
'':f[]:,:f[]:,:f[]:\
'':f[-1,1]:,:f[-1,1]:,:f[-1,1]:\
'':f[]:,:f[]:,:f[]:\
'':i[0,255]:,:i[0,255]:,:i[0,255]:\
'':>f:'':>f:\
"

#  define TX_PATTERN_CUBOID		":cu:\
'':f[]:,:f[]:,:f[]:\
'':f[-1,1]:,:f[-1,1]:,:f[-1,1]:\
'':f[]:,:f[]:,:f[]:\
'':i[0,255]:,:i[0,255]:,:i[0,255]:\
'':f[0,1]:'':f[0,1]:'':f[10,200]:\
'':|checker_on|checker_off|:\
"
# endif

#endif
