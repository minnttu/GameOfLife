#include <stdio.h>
int main(void)
{

	fscanf( fp,"%d %d", &row, &col );
	 
	while ( row != 0 && col != 0 ) {
	  if( row >= 1 && row <= MAXROW && col >=1 && col <= MAXCOL ) {
		if ( row >= rank  * maxrow + 1 && 
			 row <= ( ( rank + 1 ) * maxrow ) ) { 
		  
		   if( rank != 0 )
			   row = ( row % maxrow == 0? maxrow : row % maxrow );
	 
		   newcell.row = row;
		   newcell.col = col;
		   if ( map[row][col] == DEAD ) {
			  AddList( newcell, newlive ); // Add to list
		   }
	 
		   map[row][col] = ALIVE;
		 } 
	   } 
			 
	  fscanf( fp,"%d %d", &row, &col ); // get next coordinate pair
	} // while


	if( rank == 0 ) {
	   WriteMap( Map, generation, rank );
	   AllocateGrid( &buffer );
	 
	   for( proc = 1; proc < numProcs; proc++ ) {
		  for( row = 0; row <= maxrow; row++ )
			 MPI_Recv( buffer[row], maxcol, MPI_INT, proc, TAG, MPI_COMM_WORLD, &status );
		  WriteMap( buffer, generation, proc );
	   }
	 
		DeallocateGrid( &buffer );
	 }
	 else {
		for( row = 0; row <= maxrow; row++ )
		  MPI_Send( Map[row], maxcol, MPI_INT, 0, TAG, MPI_COMM_WORLD );
	 }
	 
 }