//
//  XTR.hpp
//  XTR-DH
//
//  Created by Hsnl on 2016/6/11.
//  Copyright © 2016年 Hsnl. All rights reserved.
//

#ifndef XTR_hpp
#define XTR_hpp
#include <iostream>
#include <vector>

#include "GaloisField2.hpp"

/*
 C{2n} = C{n}^2 - 2*(C{n})^p
 */
GFP2 C_double_n(GFP2 cn);

/*
 C{n+2} = C * C{n+1} - C1^p * C{n} + C{n-1}
 */
GFP2 C_n_next_2(GFP2 c, GFP2 cn_prev , GFP2 cn, GFP2 cn_next);

/*
 C{2n-1} = C{n-1} * C{n} - C1^p * (C{n})^p + (C{n+1})^p
*/
GFP2 C_double_n_prev(GFP2 c, GFP2 cn_prev , GFP2 cn, GFP2 cn_next);

/*
 C{2n+1} = C{n+1} * C{n} - C1 * (C{n})^p + (C{n-1})^p
 */
GFP2 C_double_n_next(GFP2 c, GFP2 cn_prev , GFP2 cn, GFP2 cn_next);


/*
 Sn = (cn_prev, cn, cn_next)
 */
std::vector<GFP2> Sn(BigNumber n, GFP2 c);


#endif /* XTR_hpp */
