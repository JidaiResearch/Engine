#ifndef RIP_REFIMPORT
#define RIP_REFIMPORT

#include <qcommon/q_shared.h>
#include <sys/sys_public.h>
#include <qcommon/MiniHeap.h>

void				FS_FreeFile(void *buffer);
void				FS_FreeFileList(char **fileList);
int					FS_Read(void *buffer, int len, fileHandle_t f);
long				FS_ReadFile(const char *qpath, void **buffer);
void				FS_FCloseFile(fileHandle_t f);
long				FS_FOpenFileRead(const char *qpath, fileHandle_t *file, qboolean uniqueFILE);
fileHandle_t		FS_FOpenFileWrite(const char *qpath, qboolean safe);
int					FS_FOpenFileByMode(const char *qpath, fileHandle_t *f, fsMode_t mode);
qboolean			FS_FileExists(const char *file);
int					FS_FileIsInPAK(const char *filename);
char **				FS_ListFiles(const char *directory, const char *extension, int *numfiles);
int					FS_Write(const void *buffer, int len, fileHandle_t f);
void				FS_WriteFile(const char *qpath, const void *buffer, int size);


void     CM_BoxTrace          ( trace_t *results, const vec3_t start, const vec3_t end, const vec3_t mins, const vec3_t maxs, clipHandle_t model, int brushmask, int capsule );
void     CM_DrawDebugSurface  ( void (*drawPoly)(int color, int numPoints, float *points) );
bool     CM_CullWorldBox      ( const cplane_t *frustum, const vec3pair_t bounds );
byte *   CM_ClusterPVS        ( int cluster );
int      CM_LeafArea          ( int leafnum );
int      CM_LeafCluster       ( int leafnum );
int      CM_PointLeafnum      ( const vec3_t p );
int      CM_PointContents     ( const vec3_t p, clipHandle_t model );

#endif