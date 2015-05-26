/**
 * \file vicEmptyClass.h
 *
 * \ingroup vicProject
 * 
 * \brief Class def header for a class vicEmptyClass
 *
 * @author vgenty
 */

/** \addtogroup vicProject

    @{*/
#ifndef VICEMPTYCLASS_H
#define VICEMPTYCLASS_H

#include <iostream>

/**
   \class vicEmptyClass
   User defined class vicEmptyClass ... these comments are used to generate
   doxygen documentation!
 */
class vicEmptyClass{

public:

  /// Default constructor
  vicEmptyClass(){}

  /// Default destructor
  ~vicEmptyClass(){}

  void say_hi() { std::cout << "yo yo yo\n"; }
  
};

#endif
/** @} */ // end of doxygen group 

