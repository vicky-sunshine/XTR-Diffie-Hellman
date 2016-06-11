
#include "XTR.hpp"

/*
 C{2n} = C{n}^2 - 2*(C{n})^p
 */
GFP2 C_double_n(GFP2 cn) {
  return power_2(cn) - 2 * power_p(cn);
}

/*
 C{n+2} = C * C{n+1} - C1^p * C{n} + C{n-1}
 */
GFP2 C_n_next_2(GFP2 c, GFP2 cn_prev , GFP2 cn, GFP2 cn_next) {
  return c * cn_next - power_p(c) * cn + cn_prev;
}

/*
 C{2n-1} = C{n-1} * C{n} - C1^p * (C{n})^p + (C{n+1})^p
 */
GFP2 C_double_n_prev(GFP2 c, GFP2 cn_prev , GFP2 cn, GFP2 cn_next) {
  return cn_prev * cn - power_p(c) * power_p(cn) + power_p(cn_next);
}

/*
 C{2n+1} = C{n+1} * C{n} - C1 * (C{n})^p + (C{n-1})^p
 */
GFP2 C_double_n_next(GFP2 c, GFP2 cn_prev , GFP2 cn, GFP2 cn_next) {
  return cn_next * cn - c * power_p(cn) + power_p(cn_prev);
}

std::vector<GFP2> Sn(BigNumber n, GFP2 c) {
 
  // Notice that, This function only consider the case n > 2
  GFP2 cneg1 = power_p(c);
  GFP2 c0 = GFP2(3);
  GFP2 c1 = c;
  GFP2 c2 = C_double_n(c1);
  GFP2 c3 = C_n_next_2(c, c0, c1, c2); // n = 1
  GFP2 c4 = C_double_n(c2);
  
  
  BigNumber m_bar, m, k=1;
  std::vector<GFP2> S3{c2, c3, c4};
  std::vector<GFP2> Sk = S3;
  
  if ( n % 2 == 0) {
    m_bar = n - 1;
  } else {
    m_bar = n;
  }

  m = (m_bar - 1) / 2;
  std::string m_bin = m.to_binary();
  
  
  for (auto i = 1; i < m_bin.size(); i++ ) {
    if(m_bin[i] == '0') {
      // S = c_2k , c_2k+1, c_2k+2
      //     sk[0], sk[1] , sk[2]
      GFP2 c4k = C_double_n(Sk[0]);
      GFP2 c4k_1 = C_double_n_prev(c, Sk[0], Sk[1], Sk[2]); // n = 2k + 1
      GFP2 c4k_2 = C_double_n(Sk[1]);
      Sk[0] = c4k;
      Sk[1] = c4k_1;
      Sk[2] = c4k_2;
      k = 2 * k;
    } else {
      // S = c_2k , c_2k+1, c_2k+2
      //     sk[0], sk[1] , sk[2]
      GFP2 c4k_2 = C_double_n(Sk[1]);
      GFP2 c4k_3 = C_double_n_next(c, Sk[0], Sk[1], Sk[2]); // n = 2k + 1
      GFP2 c4k_4 = C_double_n(Sk[2]);
      Sk[0] = c4k_2;
      Sk[1] = c4k_3;
      Sk[2] = c4k_4;
      k = 2 * k + 1;
    }
  }
  
  if ( n % 2 == 0) {
    // Sk(Sm) = C_m-1,    Cm, C_m+1
    //        =   C_m, C_m+1, C_m+2
    GFP2 c_m_nex_2 = C_n_next_2(c, Sk[0],  Sk[1],  Sk[2]);
    
    Sk[0] = Sk[1];
    Sk[1] = Sk[2];
    Sk[2] = c_m_nex_2;
    
    return Sk;
  } else {
    return Sk;
  }
  
}
