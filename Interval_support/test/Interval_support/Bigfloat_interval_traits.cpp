
#include <CGAL/basic.h>
#include <CGAL/Arithmetic_kernel.h>
#include <CGAL/Test/_test_bigfloat_interval_traits.h>

int main(){

#ifdef CGAL_HAS_GMP_ARITHMETIC_KERNEL
  {
    std::cerr << " GMP  test .." << std::flush;
    typedef CGAL::GMP_arithmetic_kernel AK;
    CGAL::test_bigfloat_interval_traits<AK::Bigfloat_interval>();
    std::cerr << " done " << std::endl;
  }
#else
    std::cerr << " GMP  test .. skipped " << std::endl;
#endif // CGAL_HAS_GMP_ARITHMETIC_KERNEL


#ifdef CGAL_HAS_LEDA_ARITHMETIC_KERNEL
  {
    std::cerr << " LEDA test .." << std::flush;
    typedef CGAL::LEDA_arithmetic_kernel AK;
    CGAL::test_bigfloat_interval_traits<AK::Bigfloat_interval>();
    std::cerr << " done " << std::endl;
  }
#else
    std::cerr << " LEDA test .. skipped " << std::endl;
#endif // CGAL_HAS_LEDA_ARITHMETIC_KERNEL


#ifdef CGAL_HAS_CORE_ARITHMETIC_KERNEL
  {
    std::cerr << " CORE test .." << std::flush;
    typedef CGAL::CORE_arithmetic_kernel AK;
    CGAL::test_bigfloat_interval_traits<AK::Bigfloat_interval>();
    std::cerr << " done " << std::endl;
  }
#else
    std::cerr << " CORE test .. skipped " << std::endl;
#endif // CGAL_HAS_CORE_ARITHMETIC_KERNEL

    return 0;
}


