#ifndef FIRST_ORDER_LOGIC_FIRST_ORDER_LOGIC
#define FIRST_ORDER_LOGIC_FIRST_ORDER_LOGIC
#include "term.hpp"
namespace first_order_logic
{
	term make_function( const std::string & s, const std::vector< term > & t )
	{ return term( new term::internal( s, t ) ); }

	term make_predicate( const std::string & s, const std::vector< term > & t )
	{ return term( new term::internal( s, t ) ); }

	term make_constant( const std::string & s )
	{ return term( new term::internal( std::string( "constant" ), { term( new term::internal( s, { } ) ) } ) ); }

	term make_not( const term & s )
	{ return term( new term::internal( std::string( "not" ), { s } ) ); }

	term make_and( const term & l, const term & r )
	{ return term( new term::internal( std::string( "and" ), { l, r } ) ); }

	term make_or( const term & l, const term & r )
	{ return term( new term::internal( std::string( "or" ), { l, r } ) ); }

	term make_imply( const term & l, const term & r )
	{ return make_or( make_not( l ), r ); }

	term make_iff( const term & l, const term & r )
	{ return make_or( make_and( l, r ), make_and( make_not( l ), make_not( r ) ) ); }

	term make_variable( const std::string & s )
	{ return term( new term::internal( std::string( "variable" ), { term( new term::internal( s, { } ) ) } ) ); }

	term make_all( const std::string & l, const term & r )
	{ return term( new term::internal( std::string( "all" ), std::vector< term >( { make_variable( l ), r } ) ) ); }

	term make_some( const std::string & l, const term & r )
	{ return term( new term::internal( std::string( "some" ), { make_variable( l ), r } ) ); }

	term make_equal( const term & l, const term & r )
	{ return term( new term::internal( std::string( "equal" ), { l, r } ) ); }
}
#endif //FIRST_ORDER_LOGIC_FIRST_ORDER_LOGIC