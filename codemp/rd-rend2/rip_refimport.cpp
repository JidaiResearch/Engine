#include "rip_refimport.h"
#include "tr_local.h"

#ifndef DEDICATED

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
int          FS_FileIsInPAK    (const char *filename, int *pChecksum                       ) { return ri.FS_FileIsInPAK    (filename, pChecksum               ); }



void     CM_BoxTrace          (trace_t *results, const vec3_t start, const vec3_t end, const vec3_t mins, const vec3_t maxs, clipHandle_t model, int brushmask, int capsule) { ri.CM_BoxTrace(results, start, end, mins, maxs, model, brushmask, capsule); }
void     CM_DrawDebugSurface  (void(*drawPoly)(int color, int numPoints, float *points) ) {        ri.CM_DrawDebugSurface(drawPoly        ); }
bool     CM_CullWorldBox      (const cplane_t *frustum, const vec3pair_t bounds         ) { return ri.CM_CullWorldBox    (frustum, bounds ); }
byte *   CM_ClusterPVS        (int cluster                                              ) { return ri.CM_ClusterPVS      (cluster         ); }
int      CM_LeafArea          (int leafnum                                              ) { return ri.CM_LeafArea        (leafnum         ); }
int      CM_LeafCluster       (int leafnum                                              ) { return ri.CM_LeafCluster     (leafnum         ); }
int      CM_PointLeafnum      (const vec3_t p                                           ) { return ri.CM_PointLeafnum    (p               ); }
int      CM_PointContents     (const vec3_t p, clipHandle_t model                       ) { return ri.CM_PointContents   (p, model        ); }


void   Cmd_ExecuteString    ( const char *text                                           ) {        ri.Cmd_ExecuteString(text                 );   }
int    Cmd_Argc             ( void                                                       ) { return ri.Cmd_Argc(                              );   }
char * Cmd_Argv             ( int arg                                                    ) { return ri.Cmd_Argv(arg                           );   }
void   Cmd_ArgsBuffer       ( char *buffer, int bufferLength                             ) {        ri.Cmd_ArgsBuffer(buffer, bufferLength    );   }
void   Cmd_AddCommand       ( const char *cmd_name, xcommand_t function, const char *desc) {        ri.Cmd_AddCommand(cmd_name, function, desc);   }
void   Cmd_RemoveCommand    ( const char *cmd_name                                       ) {        ri.Cmd_RemoveCommand(cmd_name             );   }


cvar_t * Cvar_Set               ( const char *var_name, const char *value                                      ) { return ri.Cvar_Set(var_name, value                              ); }
cvar_t * Cvar_Get               ( const char *var_name, const char *value, uint32_t flags, const char *var_desc     ) { return ri.Cvar_Get(var_name, value, flags, var_desc             ); }
cvar_t *Cvar_SetValue           ( const char *name, float value                                                ) { return ri.Cvar_SetValue(name, value                             ); }
void Cvar_CheckRange            ( cvar_t *cv, float minVal, float maxVal, qboolean shouldBeIntegral            ) {        ri.Cvar_CheckRange(cv, minVal, maxVal, shouldBeIntegral  ); }
void Cvar_VariableStringBuffer  ( const char *var_name, char *buffer, int bufsize                              ) {        ri.Cvar_VariableStringBuffer(var_name, buffer, bufsize   ); }
char * Cvar_VariableString      ( const char *var_name                                                         ) { return ri.Cvar_VariableString(var_name                          ); }
float Cvar_VariableValue        ( const char *var_name                                                         ) { return ri.Cvar_VariableValue(var_name                           ); }
int Cvar_VariableIntegerValue   ( const char *var_name                                                         ) { return ri.Cvar_VariableIntegerValue(var_name                    ); }




	qboolean   Com_TheHunkMarkHasBeenMade( void                                                         ) { return ri.Com_TheHunkMarkHasBeenMade      (                                     ); }
	void       S_RestartMusic( void                                                                     ) {        ri.S_RestartMusic                  (                                     ); }
	qboolean   SND_RegisterAudio_LevelLoadEnd( qboolean bDeleteEverythingNotUsedThisLevel               ) { return ri.SND_RegisterAudio_LevelLoadEnd  (bDeleteEverythingNotUsedThisLevel    ); }
	e_status   CIN_RunCinematic( int handle                                                             ) { return ri.CIN_RunCinematic                (handle                               ); }
	int        CIN_PlayCinematic( const char *arg0, int xpos, int ypos, int width, int height, int bits ) { return ri.CIN_PlayCinematic               (arg0, xpos, ypos, width, height, bits); }
	void       CIN_UploadCinematic( int handle                                                          ) {        ri.CIN_UploadCinematic             (handle                               ); }
	void       CL_WriteAVIVideoFrame( const byte *imageBuffer, int size                                 ) {        ri.CL_WriteAVIVideoFrame           (imageBuffer, size                    ); }
	char *     GetSharedMemory( void                                                                    ) { return ri.GetSharedMemory                 (                                     ); }
	//vm_t *     GetCurrentVM( void                                                                       ) { return ri.GetCurrentVM                    (                                     ); }
	qboolean   CGVMLoaded( void                                                                         ) { return ri.CGVMLoaded                      (                                     ); }
	int        CGVM_RagCallback( int callType                                                           ) { return ri.CGVM_RagCallback                (callType                             ); }
	window_t   WIN_Init( const windowDesc_t *desc, glconfig_t *glConfig                                 ) { return ri.WIN_Init                        (desc, glConfig                       ); }
	void       WIN_SetGamma( glconfig_t *glConfig, byte red[256], byte green[256], byte blue[256]       ) {        ri.WIN_SetGamma                    (glConfig, red, green, blue           ); }
	void       WIN_Present( window_t *window                                                            ) {        ri.WIN_Present                     (window                               ); }
	void       WIN_Shutdown( void                                                                       ) {        ri.WIN_Shutdown                    (                                     ); }
	void *     GL_GetProcAddress( const char *name                                                      ) { return ri.GL_GetProcAddress               (name                                 ); }
	qboolean   GL_ExtensionSupported( const char *extension                                             ) { return ri.GL_ExtensionSupported           (extension                            ); }

#endif

void R_Printf(int printLevel, const char *fmt, ...) {
	char buf[4096];
	va_list args;
	va_start (args, fmt);
	vsnprintf(buf, sizeof(buf), fmt, args);
	va_end(args);
	ri.Printf(printLevel, buf);
}
