#include "Mapper.h"
/*! \brief Function to test the Mapper class.
 *  \param mapper Reference to a Mapper object.
 */
void MapperTest(Mapper& mapper)
{
	mapper.updateMap();
	mapper.showMap();
	mapper.recordMap();
}