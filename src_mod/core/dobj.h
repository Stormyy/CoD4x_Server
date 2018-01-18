// dobj.h and dobj.c contains structure of ingame DObj and various functions to work with it.

#ifndef __DOBJ_H__
#define __DOBJ_H__

#include "q_shared.h"
#include "entity.h"
#include <xassets/xmodel.h>
#include "dobj_part_cache.h"
#include "qcommon_io.h"

typedef struct DObjSkeletonPartMatrix_s // Same as DObjAnimMat_t? Need confirmation!
{
	float p1[4];
	float p2[4];
}DObjSkeletonPartMatrix_t;


typedef struct DSkelPartBits_s
{
	int anim[4];
	int control[4];
	int skel[4];
} DSkelPartBits_t;


typedef struct DSkel_s
{
	DSkelPartBits_t partBits;
	int timeStamp;
	DObjSkeletonPartMatrix_t *mat;
} DSkel_t;


typedef struct DObj_s
{
	int *tree;
	WORD duplicateParts;
	WORD entNum;
	byte duplicatePartsSize;
	byte numModels;
	byte numBones;
	byte pad;
	int ignoreCollision;
	int locked;
	DSkel_t skel;
	int radius;
	int hidePartBits[4];
	XModel_t **models;
} DObj_t;


DObj_t* Com_GetServerDObj(int entNum);
qboolean SV_DObjExists(gentity_t* ent);
void DObjDumpInfo(DObj_t* dobj);
extern signed int (__cdecl *GetDObjPartInfo)(gentity_t *ent, int partNameIdx, DObjPartCacheVectorSet_t *vectorSet);
extern void (*DObjInit)();
extern void (*DB_LoadDObjs)();

#define serverObjMap ((WORD*)  0x088E8500)    // Max = 0x400 (1024)
#define objBuf       ((DObj_t*)0x088E8D20)    // Max = 0x800 (2048)

#endif //__DOBJ_H__
