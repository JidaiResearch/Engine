#include "rip_refimport.h"

#include "tr_local.h"

#if 1

void         FS_FreeFile       (void *buffer                                               ) {        ri.FS_FreeFile       (buffer                            ); }
void         FS_FreeFileList   (char **fileList                                            ) {        ri.FS_FreeFileList   (fileList                          ); }
void         FS_FCloseFile     (fileHandle_t f                                             ) {        ri.FS_FCloseFile     (f                                 ); }
void         FS_WriteFile      (const char *qpath, const void *buffer, int size            ) {        ri.FS_WriteFile      (qpath, buffer, size               ); }
int          FS_Read           (void *buffer, int len, fileHandle_t f                      ) { return ri.FS_Read           (buffer, len, f                    ); }
long         FS_ReadFile       (const char *qpath, void **buffer                           ) { return ri.FS_ReadFile       (qpath, buffer                     ); }
long         FS_FOpenFileRead  (const char *qpath, fileHandle_t *file, qboolean uniqueFILE ) { return ri.FS_FOpenFileRead  (qpath, file, uniqueFILE           ); }
fileHandle_t FS_FOpenFileWrite (const char *qpath, qboolean safe                           ) { return ri.FS_FOpenFileWrite (qpath, safe                       ); }
int          FS_FOpenFileByMode(const char *qpath, fileHandle_t *f, fsMode_t mode          ) { return ri.FS_FOpenFileByMode(qpath, f, mode                    ); }
qboolean     FS_FileExists     (const char *file                                           ) { return ri.FS_FileExists     (file                              ); }
char **      FS_ListFiles      (const char *directory, const char *extension, int *numfiles) { return ri.FS_ListFiles      (directory, extension, numfiles    ); }
int          FS_Write          (const void *buffer, int len, fileHandle_t f                ) { return ri.FS_Write          (buffer, len, f                    ); }
//int FS_FileIsInPAK(const char *filename) { return ri.FS_FileIsInPAK(filename); }



void     CM_BoxTrace          (trace_t *results, const vec3_t start, const vec3_t end, const vec3_t mins, const vec3_t maxs, clipHandle_t model, int brushmask, int capsule) { ri.CM_BoxTrace(results, start, end, mins, maxs, model, brushmask, capsule); }
void     CM_DrawDebugSurface  (void(*drawPoly)(int color, int numPoints, float *points) ) {        ri.CM_DrawDebugSurface(drawPoly        ); }
bool     CM_CullWorldBox      (const cplane_t *frustum, const vec3pair_t bounds         ) { return ri.CM_CullWorldBox    (frustum, bounds ); }
byte *   CM_ClusterPVS        (int cluster                                              ) { return ri.CM_ClusterPVS      (cluster         ); }
int      CM_LeafArea          (int leafnum                                              ) { return ri.CM_LeafArea        (leafnum         ); }
int      CM_LeafCluster       (int leafnum                                              ) { return ri.CM_LeafCluster     (leafnum         ); }
int      CM_PointLeafnum      (const vec3_t p                                           ) { return ri.CM_PointLeafnum    (p               ); }
int      CM_PointContents     (const vec3_t p, clipHandle_t model                       ) { return ri.CM_PointContents   (p, model        ); }


#endif