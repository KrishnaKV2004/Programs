/*
June 1,2021
Delete variable K2�v[2]
Fixed restart ()

ODE�ɂ��UVC(��̐�������)�̌��� 2021 4/11
*/

#include <ode.h>
#include <drawstuff.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <fstream>
#include <math.h>
#include <conio.h>
#include "biped.h"
#include "core.h"

//�֐���`
static	void command		(int cmd);
static	void nearCallback(void *data, dGeomID o1, dGeomID o2);
static	void simLoop		(int pause);
static	void setJoint	(jointStr *j, char k, bodyStr *b1, bodyStr *b2, char a,  double x, double y, double z, double dn, double up, double t, double tk, int s);
static	void setBody		(bodyStr  *b, char k, char	 c,	 double l,	 double w, double h, double r, double x, double y, double z,  int ge,   double ma);

static	void createBody	();
void			 destroyBot	();
void			 restart		();
static	void start		();

// select correct drawing functions
#ifdef  dDOUBLE				 //�P���x�Ɣ{���x�̗����ɑΉ����邽�߂̂��܂��Ȃ�
#define dsDrawBox	  dsDrawBoxD
#define dsDrawSphere	  dsDrawSphereD
#define dsDrawCylinder dsDrawCylinderD
#define dsDrawCapsule  dsDrawCapsuleD
#endif

//�Ԑڊp�x
double K0W[2]={0,0};		//�Ҋ֐ߑO����������p
double K1W[2]={0,0};		//�Ҋ֐߉����������p
//double K2W[2]={0,0};	//�Ҋ֐߃��[�����������p
double HW [2]={0,0};		//�G�֐ߏ����p
double A0W[2]={0,0};		//����㉺���������p
double A1W[2]={0,0};		//���񉡕��������p
double U0W[2]={0,0};		//���O����������p
double U1W[2]={0,0};		//��������������p
double U2W[2]={0,0};		//�����[�������p

//�Z���T�֘A
double fbRad=0;			//���O��p�x
double lrRad=0;			//�����E�p�x
double fbAV=0;			//���O��p���x
double lrAV=0;			//�����E�p���x
double asiPress_r=0;		//�E��������
double asiPress_l=0;		//����������

//�e��ϐ���`
double softERP;			//�_�炩���A���ݍ���
double softCFM;			//�_�炩���A�e��
double bounce;			//�����W��
double bounce_vel;		//�����Œᑬ�x

static dWorldID world;				//���͊w�v�Z�p���[���h
static dSpaceID space;				//�Փˌ��o�p�X�y�[�X
static dJointGroupID contactgroup;	//�R���^�N�g�O���[�v
static dGeomID ground;				//�n��

dMatrix3 R;
const double* Rot;		// ��]�s��擾
int	   uvcOff=0;			//UVC�N���t���O
unsigned char walkF=0;	//���s�t���O	�ib0:���s  b1:��  b2:���j
int	bodyCount;			//�{�f�B�z��J�E���g�l
int	jointCount;			//�W���C���g�z��J�E���g�l
static struct dJointFeedback feedback[50];	//�W���C���g�t�B�[�h�o�b�N�\����


//###############  �e��\���́@###############
bodyStr *body[50];	//bodyStr�A�h���X�i�[�z��
bodyStr solep_r;		//�������̓Z���T
bodyStr solep_l;	
bodyStr sole_r;		//����
bodyStr sole_l;	
bodyStr A1_r;		//���񃍁[��	
bodyStr A1_l;	
bodyStr A0_r;		//����s�b�`
bodyStr A0_l;
bodyStr S_r;			//��
bodyStr S_l;
bodyStr H_r;			//�G
bodyStr H_l;
bodyStr M_r;			//��
bodyStr M_l;
bodyStr K0_r;		//�Ҋ֐߃s�b�`
bodyStr K0_l;
bodyStr K1_r;		//�Ҋ֐߃��[��
bodyStr K1_l;
bodyStr DOU;			//��
bodyStr HEADT;		//��
bodyStr base;		//�Ւf�@��
bodyStr pole;		//�Ւf�@�_
bodyStr BALL1;		//�{�[��

jointStr *joint[50];	//jointStr�A�h���X�i�[�z��
jointStr soleJ_r;	//�����Z���T
jointStr soleJ_l;
jointStr A1J_r;		//���񃍁[��
jointStr A1J_l;
jointStr A0J_r;		//����s�b�`
jointStr A0J_l;
jointStr SJ_r;		//���Œ�
jointStr SJ_l;
jointStr HJ_r;		//�G
jointStr HJ_l;
jointStr MJ_r;		//�ڌ���
jointStr MJ_l;
jointStr M2J_r;		//�ڌ���2
jointStr M2J_l;
jointStr K0J_r;		//�Ҋ֐߃s�b�`
jointStr K0J_l;
jointStr K1J_r;		//�Ҋ֐߃��[��
jointStr K1J_l;
jointStr K2J_r;		//�Ҋ֐߃��[
jointStr K2J_l;
jointStr HEADJ;		//���Œ�
jointStr poleJ;		//�|�[���̃W���C���g
jointStr baseJ;		//���̌Œ�
jointStr headJ;		//���̌Œ�

//###############  �N���X�̎��̉��@###############

core co;	//�ŉ��w�A�g���j�b�g�J�v�Z���̎��̉�


//--------------------------------- command ----------------------------------------
static void command (int cmd){
	static int mag = 30;

	switch (cmd) {
		//// �O�͈�� ////
		case 'j':case 'J':
			printf("�e��\n");
			dBodyAddForce(DOU.b, -20,0,0);
			break;
		case 'k':case 'K':
			printf("�e��\n");
			dBodyAddForce(DOU.b,  20,0,0);
			break;
		case 'p':case 'P':
			printf("�e��\n");
			dBodyAddForce(DOU.b, 0,20,0);
			break;
		case 'l':case 'L':
			printf("�e��\n");
			dBodyAddForce(DOU.b,  0,-20,0);
			break;

		//// ���� ////
		case 'w':				//���s�J�n
			printf("���s�J�n\n");
			walkF=0x01;
			break;
		case 'r':case 'R':		//������
			printf("������\n");
			restart ();
			break;
		case 'q':case 'Q':		//�I��
			printf("�I��\n");
			exit(0);
			break;
		case 'u':case 'U':		//UVC ON/OFF
			if(uvcOff==0){
				uvcOff=1;
			}
			else{
				uvcOff=0;
			}
			break;
	}
}


//----------------------------------- nearCallback --------------------------------------
static void nearCallback (void *data, dGeomID o1, dGeomID o2){
	int i,n;
	const int N = 10;
	dContact contact[N];
	dBodyID b1 = dGeomGetBody(o1);
	dBodyID b2 = dGeomGetBody(o2);
	if (b1 && b2 && dAreConnectedExcluding(b1,b2,dJointTypeContact)) return;
	n = dCollide (o1,o2,N,&contact[0].geom,sizeof(dContact));
	if (n > 0) {
		for (i=0; i<n; i++) {
			contact[i].surface.mode		= dContactBounce | dContactSoftERP | dContactSoftCFM;
			contact[i].surface.soft_cfm	= 0.00005;											//�_�炩���A�e��
			contact[i].surface.soft_erp	= 0.1;												//�_�炩���A���ݍ���
			if((ground != o1) && (ground != o2))	contact[i].surface.mu		= 0.2;				//���̊Ԗ��C
			else									contact[i].surface.mu		= 5;					//�n�ʊԖ��C
			contact[i].surface.bounce		= 0;													// bouncing the objects
			contact[i].surface.bounce_vel	= 0;													// bouncing velocity
			dJointID c = dJointCreateContact (world,contactgroup,&contact[i]);					//�W���C���g����
			dJointAttach (c,dGeomGetBody(contact[i].geom.g1),dGeomGetBody(contact[i].geom.g2));	//�W���C���g����������
	    }
	}
}


//--------------------------------- control ----------------------------------------
// hinge control 
static void control(){
	double kp = 100.0;
	double k;
	int i;
	for (i=0;i<jointCount;i++){
		switch (joint[i]->k) {
			case 'h':
				k = kp * (joint[i]->t - dJointGetHingeAngle(joint[i]->j));
				if(abs(k) > joint[i]->tm){
					if(k > 0){k = joint[i]->tm;}
					else{k = -joint[i]->tm;}
				}
				dJointSetHingeParam(joint[i]->j, dParamVel, k );
				dJointSetHingeParam(joint[i]->j, dParamFMax, joint[i]->tk); 
				break;
			case 'd':
				k = joint[i]->t - dJointGetSliderPosition(joint[i]->j);
				dJointSetSliderParam(joint[i]->j, dParamVel,  k * 100);
				dJointSetSliderParam(joint[i]->j, dParamFMax, 300); 
				break;
		}
	}
}


//--------------------------------- simLoop ----------------------------------------
//	simulation loop
static void simLoop (int pause){
	int i;
	char a;
	static int mag = 3;

	double sides[3];
	dJointFeedback *fb;
	dVector3 headVel1;
	dVector3 headVel2;

	Sleep(1);			//�`�摬�x�̒���
	if(kbhit()){
		a=getchar();		//�L�[�Ǎ�
		command (a);
	}

	if (!pause) {
		//******** ���̂R�s�͍ŏ��ɒu���ׂ� ********
		dSpaceCollide (space,0,&nearCallback);	//�Փ˂������ȃW�I���g���̃y�A�W�c��T��
		dWorldStep (world,0.01);				//�V�~�����[�V�������P�X�e�b�v�w�莞�Ԑi�߂�
		dJointGroupEmpty (contactgroup);		//�W���C���g�O���[�v����ɂ���

		//******** �������͌��o ********
		fb = dJointGetFeedback(soleJ_r.j);
		asiPress_r = fb->f1[2];				//�E��(����y)����
		fb = dJointGetFeedback(soleJ_l.j);
		asiPress_l = fb->f1[2];				//����(����y)����

		//******** ���O�㍶�E�p�x���o ********
		Rot = dBodyGetRotation(HEADT.b);		//��]�s��擾
		fbRad = asin(Rot[8]);					//���O��p�x(���ɋ�������)
		lrRad = asin(Rot[9]);					//�����E�p�x�i�E�X�������j

		//******** ���O�㍶�E�p���x���o ********
		Rot = dBodyGetAngularVel(HEADT.b);	//��]�s��擾
		fbAV = Rot[1];						//���O��p�x(���ɋ�������)
		lrAV = Rot[0];						//�����E�p�x�i�E�X�������j

		K0J_r.t	=K0W[0];			//�Ҋ֐ߑO����������p
		K1J_r.t	=K1W[0];			//�Ҋ֐߉����������p
		HJ_r.t	=HW [0];			//�G�֐ߏ����p
		A0J_r.t	=A0W[0];			//����㉺���������p
		A1J_r.t	=A1W[0];			//���񉡕��������p

		K0J_l.t	=K0W[1];			//�Ҋ֐ߑO����������p
		K1J_l.t	=K1W[1];			//�Ҋ֐߉����������p
		HJ_l.t	=HW [1];			//�G�֐ߏ����p
		A0J_l.t	=A0W[1];			//����㉺���������p
		A1J_l.t	=A1W[1];			//���񉡕��������p

		co.walk();				//���s����
		control();				//���[�^�쓮
	}

	for (i=0;i<bodyCount;i++){
		switch (body[i]->c) {
			case 'g':
				dsSetColor (0,1,0);
				break;
			case 'r':
				dsSetColor (1,0,0);
				break;
			case 'b':
				if(uvcOff==0)dsSetColor(0.3 ,0.3, 2.0);
				else			dsSetColor(2.0, 0.3, 0.3);
				break;
			case 'y':
	 			dsSetColor (1,1,0);
				break;
			case 'w':
	 			dsSetColor (1,1,1);
				break;
			case 'd':
	 			dsSetColor (0.8,0.8,0.8);
				break;
			default:
				break;
		}
		switch (body[i]->k) {
			case 'b':
				sides[0] = body[i]->l; sides[1] = body[i]->w; sides[2] = body[i]->h;
				dsDrawBox (dBodyGetPosition(body[i]->b),dBodyGetRotation(body[i]->b),sides);						//���`�\��
				break;
			case 's':
	 			dsDrawSphere (dBodyGetPosition(body[i]->b),dBodyGetRotation(body[i]->b),body[i]->r);				//���`�\��
				break;
			case 'c':
				dsDrawCapsule (dBodyGetPosition(body[i]->b),dBodyGetRotation(body[i]->b),body[i]->l,body[i]->r);	//�J�v�Z���`�\��
				break;
			case 'y':
				dsDrawCylinder (dBodyGetPosition(body[i]->b),dBodyGetRotation(body[i]->b),body[i]->l,body[i]->r);	//�~���`�\��
				break;
			default:
				break;
		}
	}
}


//----------------------------------- setBody --------------------------------------
//	�z��Ƀ{�f�B����ݒ肷��

static void setBody (bodyStr *b, char k,    char c, double l, double w, double h, double r, double x, double y, double z, int ge, double ma){
//�����F�@                    �{�f�B�̎��     �F�@    �����@     ���@      ����     ���a�@  �O��ʒu   ���E�ʒu�@�㉺�ʒu  �W�I���g�@�d��

	dMass m;

//�X�P�[������
	l/=1000;
	w/=1000;
	h/=1000;
	r/=1000;
	x/=1000;
	y/=1000;
	z/=1000;

	//�\���̂ɋL�^����
	b-> k = k;			//�{�f�B�̎�ނ��L�^
	b-> c = c;			//�{�f�B�̐F�̎�ނ��L�^
	b-> l = l;			//�{�f�B�̒������L�^
	b-> w = w;			//�{�f�B�̕������L�^
	b-> h = h;			//�{�f�B�̍������L�^
	b-> r = r;			//�{�f�B�̔��a���L�^
	b-> ge = ge;			//�W�I���g���ݒ� �L/��
	b-> e = 1;			//�{�f�B�L���ݒ�

	x += 2;				//2m��O�ɒu���Ēn�ʏ�Q���������

	body[bodyCount] = b;	//�\���̂̃A�h���X���i�[����
	++bodyCount;			//�{�f�B���J�E���g�A�b�v

	//�{�f�B�ƃW�I���g���̐����ƁA���ʁA�ʒu�A�֘A����ݒ�
	switch (b->k) {
		case 'b':	//���^
			b->b = dBodyCreate (world);						// ���̂̑��݂𐶐�(�{�f�BID�ݒ�)
			dMassSetZero(&m);									// ���ʃp�����[�^������
			dMassSetBoxTotal (&m,ma,b->l,b->w,b->h);			// ���̂̏d�ʐݒ�
			dBodySetMass (b->b,&m);							// ���̂̏d�ʕ��z�ݒ�
			dBodySetPosition (b->b,x,y,(z));					// ���̂̏����ʒu
			if(ge > 0){
				b->g = dCreateBox (space,b->l,b->w,b->h);		// ���̂̊􉽏��𐶐��i�W�I���g��ID�ݒ�j
				dGeomSetBody (b->g,b->b);						// ���̂́w���݁x�Ɓw�􉽏��x�̈�v
			}
			break;
		case 's':	//���`
			b->b = dBodyCreate (world);						// ���̂̑��݂𐶐�(�{�f�BID�ݒ�)
			dMassSetZero(&m);									// ���ʃp�����[�^������
			dMassSetSphereTotal (&m,ma,b->r);					// ���̂̏d�ʐݒ�
			dBodySetMass (b->b,&m);							// ���̂̏d�ʕ��z�ݒ�
			dBodySetPosition (b->b,x,y,z);					// ���̂̏����ʒu
			if(ge > 0){
				b->g = dCreateSphere (space,b->r);			// ���̂̊􉽏��𐶐��i�W�I���g��ID�ݒ�j
				dGeomSetBody (b->g,b->b);						// ���̂́w���݁x�Ɓw�􉽏��x�̈�v
			}
			break;
		case 'c':	//�J�v�Z���`
			b->b = dBodyCreate (world);						// ���̂̑��݂𐶐�(�{�f�BID�ݒ�)
			dMassSetZero(&m);									// ���ʃp�����[�^������
			dMassSetCapsuleTotal(&m,ma,3,b->r,b->l);			// ���̂̏d�ʐݒ�
			dBodySetMass (b->b,&m);							// ���̂̏d�ʕ��z�ݒ�
			dBodySetPosition (b->b,x,y,(b->l/2+z));			// ���̂̏����ʒu
			if(ge > 0){
				b->g = dCreateCapsule (space,b->r,b->l);		// ���̂̊􉽏��𐶐��i�W�I���g��ID�ݒ�j
				dGeomSetBody (b->g,b->b);						// ���̂́w���݁x�Ɓw�􉽏��x�̈�v
			}
			break;
		case 'y':	//�~���`
			b->b = dBodyCreate (world);						// ���̂̑��݂𐶐�(�{�f�BID�ݒ�)
			dMassSetZero(&m);									// ���ʃp�����[�^������
			dMassSetCylinderTotal(&m,ma,3,b->r,b->l);			// ���̂̏d�ʐݒ�
			dBodySetMass (b->b,&m);							// ���̂̏d�ʕ��z�ݒ�
			dBodySetPosition (b->b,x,y,(z));					// ���̂̏����ʒu
			if(ge > 0){
				b->g = dCreateCylinder (space,b->r,b->l);		// ���̂̊􉽏��𐶐��i�W�I���g��ID�ݒ�j
				dGeomSetBody (b->g,b->b);						// ���̂́w���݁x�Ɓw�􉽏��x�̈�v
			}
			break;
		default:
			break;
	}
}


//---------------------------------- setJoint ---------------------------------------
//	�W���C���g�𐶐�����

static void setJoint (jointStr *j, char k, bodyStr *b1, bodyStr *b2, char a, double x, double y, double z){
//�����F�@            �Ώ�Joint�@Joint���   Body�ԍ�1  �@Body�ԍ�2�@ �ݒ莲  �O��ʒu  ���E�ʒu�@�㉺�ʒu

	x/=1000;
	y/=1000;
	z/=1000;

	//�\���̂ɋL�^����
	j -> k	= k;			//��ނ��L�^
	j -> x	= x;			//X���W���L�^
	j -> y	= y;			//X���W���L�^
	j -> z	= z;			//X���W���L�^
	j -> c	= 0;			//�ėp�J�E���^
	j -> t	= 0;			//�Ԑڊp�x
	j -> t2	= 0;			//�Ԑڊp�x2
	j -> mode = 0;		//�쓮���[�h
	j -> pn	= 0;			//�����̓J�E���^
	j -> tm	= 44.06;		//8.06�ő�p���x
	j -> tm2	= 8.06;		//8.06�ő�p���x
	j -> tk	= 2.45;		//2.45�g���N 25kgfcm   (25/100)/9.8=2.45
	j -> tk2	= 2.45;		//�g���N2

	x += 2;					//2m��O�ɒu���Ēn�ʏ�Q���������
	joint[jointCount] = j;	//�z��̃A�h���X���i�[����
	++jointCount;			//�z��J�E���^�A�J�E���g�A�b�v

	switch (k) {
		case 'h':	//�q���W�W���C���g
			j -> j = dJointCreateHinge(world, 0);			// �q���W�W���C���g�̐����ƋL�^
			dJointAttach(j -> j, b1->b, b2->b);			// �q���W�W���C���g�̎�t
			dJointSetHingeAnchor(j -> j, x, y, z);			// ���S�_�̐ݒ�
			switch (a) {		//����ݒ�
				case 'x': dJointSetHingeAxis(j -> j, 1, 0, 0); break;	// X���̐ݒ�
				case 'z': dJointSetHingeAxis(j -> j, 0, 0, 1); break;	// Z���̐ݒ�
				default : dJointSetHingeAxis(j -> j, 0, 1, 0); break;	// Y���̐ݒ�
			}
			break;
		case 'd':	//�X���C�_�[�W���C���g�i�_���p�[�j
			j -> j = dJointCreateSlider(world, 0);			// �X���C�_�[�W���C���g�̐����ƋL�^
			dJointAttach(j -> j, b1->b, b2->b);			// �X���C�_�[�W���C���g�̎�t
			dJointSetSliderAxis(j -> j, 0, 0, 1);			// ���S�_�̐ݒ�
			break;
		case 'f':	//�Œ�W���C���g
			j -> j = dJointCreateFixed(world, 0);			// �Œ�W���C���g�̐����ƋL�^
			dJointAttach(j -> j, b1->b, b2->b);			// �Œ�W���C���g�̎�t
			dJointSetFixed(j -> j);						// �Œ�W���C���g�ɂ̐ݒ�
			break;
		case 'g':	//���Œ�W���C���g
			j -> j = dJointCreateFixed(world, 0);			// �Œ�W���C���g�̐����ƋL�^
			dJointAttach(j -> j, b1->b, 0);				// �Œ�W���C���g�̎�t�i���Œ�j
			dJointSetFixed(j -> j);						// �Œ�W���C���g�ɂ̐ݒ�
			break;
		default:
			break;
	}
}


//---------------------------------- createBody ---------------------------------------
//	�e���̃p�[�c�T�C�Y�����w�肵�ă��{�b�g��g�ݗ��Ă�
static void createBody (){
	double	fw	= 21;		//�r�̊Ԋu�i���S����̋����j
	double	fmax= 1000;		//�쓮�g���N�W���l
	double	kmax= 1000;		//�ő�p���x

	softERP		= 0.2;		//�e��
	softCFM		= 0.0001;	//���ݍ���
	bounce		= 0.01;		//�����W��
	bounce_vel	= 0.02;		//�����Œᑬ�x
	bodyCount	= 0;			//�{�f�B�z��J�E���g�l
	jointCount	= 0;			//�W���C���g�z��J�E���g�l

//	####################
//	#### �{�f�B���� ####
//	####################
//						    ��� �F  L�@  W    H     R      X     Y     Z   �W�I���g �d��

	setBody  (&HEADT,		'c','w',	15,  0,	  0,   21,	  0,	   0,	340,		0,	0.16);	//��
	setBody  (&DOU,			'b','b',	40,  84,  130,  0,	  0,	   0,	260,		1,	1.24);	//��

	setBody  (&K0_r,			'y','d',	34,	 0,	  0,	   12,	  0,   -fw,	195,		0,	0.05);	//�Ҋ֐߃s�b�`
	dRFromAxisAndAngle(R, 1, 0, 0, -M_PI_2);//��]
	dBodySetRotation(K0_r.b, R);
	setBody  (&K0_l,			'y','d',	34,	 0,	  0,	   12,	  0,    fw,	195,		0,	0.05);
	dRFromAxisAndAngle(R, 1, 0, 0, -M_PI_2);//��]
	dBodySetRotation(K0_l.b, R);
	setBody  (&K1_r,			'y','w',	34,	 0,	  0,   12,	  0,   -fw,	195,		0,	0.05);	//�Ҋ֐߃��[��
	dRFromAxisAndAngle(R, 0, 1, 0, -M_PI_2);//��]
	dBodySetRotation(K1_r.b, R);
	setBody  (&K1_l,			'y','w',	34,	 0,	  0,   12,	  0,    fw,	195,		0,	0.05);
	dRFromAxisAndAngle(R, 0, 1, 0, -M_PI_2);//��]
	dBodySetRotation(K1_l.b, R);
	setBody  (&M_r,			'b','d',	20,	 26,	  90,  0,	  0,   -fw,	150,		0,	0.08);	//��
	setBody  (&M_l,			'b','d',	20,	 26,	  90,  0,	  0,    fw,	150,		0,	0.08);
	setBody  (&H_r,			'y','d',	34,	 0,	  0,   12,	  0,   -fw,  105,	0,	0.03);	//�G
	dRFromAxisAndAngle(R, 1, 0, 0, -M_PI_2);//��]
	dBodySetRotation(H_r.b, R);
	setBody  (&H_l,			'y','d',	34,	 0,	  0,	   12,	  0,    fw,  105,	0,	0.03);
	dRFromAxisAndAngle(R, 1, 0, 0, -M_PI_2);//��]
	dBodySetRotation(H_l.b, R);
	setBody  (&S_r,			'b','d',	20,	 26,  90,   0,	  0,   -fw,	60,		1,	0.04);	//��
	setBody  (&S_l,			'b','d',	20,	 26,  90,   0,	  0,    fw,	60,		1,	0.04);
	setBody  (&A0_r,			'y','d',	34,	 0,   0,	   12,	  0,   -fw,	15,		0,	0.02);	//����s�b�`
	dRFromAxisAndAngle(R, 1, 0, 0, -M_PI_2);//��]
	dBodySetRotation(A0_r.b, R);
	setBody  (&A0_l,			'y','d',	34,	 0,	  0,	   12,	  0,    fw,	15,		0,	0.02);
	dRFromAxisAndAngle(R, 1, 0, 0, -M_PI_2);//��]
	dBodySetRotation(A0_l.b, R);
	setBody  (&A1_r,			'y','w',	34,	 0,	  0,	   12,	  0,   -fw,	15,		0,	0.02);	//���񃍁[��
	dRFromAxisAndAngle(R, 0, 1, 0, -M_PI_2);//��]
	dBodySetRotation(A1_r.b, R);
	setBody  (&A1_l,			'y','w',	34,	 0,	  0,   12,	  0,    fw,	15,		0,	0.02);
	dRFromAxisAndAngle(R, 0, 1, 0, -M_PI_2);//��]
	dBodySetRotation(A1_l.b, R);
	setBody  (&sole_r,		'b','w',	55,	 40,	  2,		0,	  0,   -fw,	6.0,		0,	0.01);	//����
	setBody  (&sole_l,		'b','w',	55,	 40,	  2,		0,	  0,    fw,	6.0,		0,	0.01);
	setBody  (&solep_r,		'b','r',	55,	 40,	  6,		0,	  0,   -fw,	3.0,		1,	0.01);	//�\�[���Z���T
	setBody  (&solep_l,		'b','r',	55,	 40,	  6,		0,	  0,    fw,	3.0,		1,	0.01);

	setBody  (&BALL1,		's','d', 0,	 0,	  0,	   50,	  900,  140,  50,		1,	4.0);	//�Ւf�@��
	setBody  (&base,			'y','d',	220,	 0,	  0,		24,	  210,	180,	150,		0,	0.01);	//�Ւf�@�_
	setBody  (&pole,			'y','y',	500,	 0,	  0,		8,	  210,	0,	230,		1,	0.0001);	//�{�[��
	dRFromAxisAndAngle(R, 1, 0, 0, -M_PI_2);//��]
	dBodySetRotation(pole.b, R);


//	######################
//	####�W���C���g����####
//	######################
//							���	 B�ԍ�1		B�ԍ�2   ��		X		 Y		Z

	setJoint(&HEADJ,			'f',	&HEADT,		&DOU,	'z',		0,		 0,		360);	//���Œ�p
	setJoint(&K0J_r,			'h',	&K1_r,		&K0_r,	'y',		0,		-fw,		195);	//�Ҋ֐߃s�b�`
	setJoint(&K0J_l,			'h',	&K1_l,		&K0_l,	'y',		0,		 fw,		195);
	setJoint(&K1J_r,			'h',	&DOU,		&K1_r,	'x',		0,		-fw+11,	195);	//�Ҋ֐߃��[��
	setJoint(&K1J_l,			'h',	&K1_l,		&DOU,	'x',		0,		 fw-11,	195);
	setJoint(&MJ_r,			'f',	&M_r,		&K0_r,	'y',		0,		-fw,		128);	//�ڌŒ�p
	setJoint(&MJ_l,			'f',	&M_l,		&K0_l,	'y',		0,		 fw,		128);
	setJoint(&M2J_r,			'f',	&H_r,		&M_r,	'y',		0,		-fw,		128);	//�ڌŒ�p
	setJoint(&M2J_l,			'f',	&H_l,		&M_l,	'y',		0,		 fw,		128);
	setJoint(&HJ_r,			'h',	&S_r,		&H_r,	'y',		0,		-fw,		105);	//�G�֐�
	setJoint(&HJ_l,			'h',	&S_l,		&H_l,	'y',		0,		 fw,		105);
	setJoint(&SJ_r,			'f',	&S_r,		&A0_r,	'y',		0,		-fw,		60);		//���Œ�p
	setJoint(&SJ_l,			'f',	&S_l,		&A0_l,	'y',		0,		 fw,		60);
	setJoint(&A0J_r,			'h',	&A0_r,		&A1_r,	'y',		0,		-fw,		15);		//����s�b�`
	setJoint(&A0J_l,			'h',	&A0_l,		&A1_l,	'y',		0,		 fw,		15);
	setJoint(&A1J_r,			'h',	&A1_r,		&sole_r,	'x',		0,		-fw+11,	15);		//���񃍁[��
	setJoint(&A1J_l,			'h',	&sole_l,		&A1_l,	'x',		0,		 fw-11,	15);
	setJoint(&soleJ_r,		'd',	&solep_r,	&sole_r,	'x',		0,		-fw,		6);		//�\�[�����̓Z���T
	setJoint(&soleJ_l,		'd',	&solep_l,	&sole_l,	'x',		0,		 fw,		6);

	setJoint(&baseJ,			'g',	&base,		&base,	'x',		210,		 180,	0);		//�Ւf�@���Œ�p
	setJoint(&poleJ,			'h',	&pole,		&base,	'z',		210,		 180,	110);	//�Ւf�@�_�q���W
	poleJ.tm=7;
	poleJ.tk=0.2;

	dJointSetFeedback(soleJ_r.j,			&feedback[0]);
	dJointSetFeedback(soleJ_l.j,			&feedback[1]);
}


//--------------------------------- destroy ----------------------------------------
//	���{�b�g�̔j��
void destroyBot (){
	int i;
	for (i=0;i<jointCount;i++){
		if(joint[i]->e > 0){dJointDestroy (joint[i]->j);}	//�W���C���g�j��
	}
	for (i=0;i<bodyCount;i++){
		if(body[i]->e > 0){dBodyDestroy (body[i]->b);}		//�{�f�B�L���Ȃ�j��
		if(body[i]->ge > 0){dGeomDestroy (body[i]->g);}	//�W�I���g���ݒ肳��Ă���j��
	}
	dJointGroupDestroy (contactgroup);
}


//--------------------------------- restart ----------------------------------------
//	���X�^�[�g
void restart (){
	destroyBot ();
	contactgroup = dJointGroupCreate (0);	//�ڐG�_�̃O���[�v���i�[������ꕨ
	createBody();						//���{�b�g����
	dWorldSetGravity (world, 0, 0, -9.8);	//�d�͐ݒ�
	co.mode=0;
	co.autoHs=180;
	walkF=0;
	uvcOff=0;

	K0W[0]=0;			//�Ҋ֐ߑO�����
	K1W[0]=0;			//�Ҋ֐߉�����
	HW [0]=0;			//�G�֐�
	A0W[0]=0;			//����㉺����
	A1W[0]=0;			//���񉡕���
	K0W[1]=0;			//�Ҋ֐ߑO�����
	K1W[1]=0;			//�Ҋ֐߉�����
	HW [1]=0;			//�G�֐�
	A0W[1]=0;			//����㉺����
	A1W[1]=0;			//���񉡕���
}


//--------------------------------- start ----------------------------------------
//	start simulation - set viewpoint
static void start(){
	static float xyz[3] = {2.3, -0.3, 0.18};	//���_�̈ʒu
	static float hpr[3] = {135,0,0};	//�����̕���
	dsSetViewpoint (xyz,hpr);//�J�����̐ݒ�
}


//------------------------------------ main -------------------------------------
int main (int argc, char **argv){
	dMass m;
	dInitODE(); // ODE�̏�����

	// setup pointers to drawstuff callback functions
	dsFunctions fn;
	fn.version = DS_VERSION;
	fn.start = &start;
	fn.step = &simLoop;
//	fn.command = &command;�@//Windows10���痘�p�ł��Ȃ��Ȃ���
	fn.stop = 0;
	fn.path_to_textures = "c:/ode-0.13/drawstuff/textures";
	if(argc==2)fn.path_to_textures = argv[1];

	//   create world
	world = dWorldCreate();				//�V�~�����[�V�������[���h����
	space = dHashSpaceCreate (0);			//�Փˌ��o�p�X�y�[�X����
	contactgroup = dJointGroupCreate (0);	//�ڐG�_�̃O���[�v���i�[������ꕨ
	dWorldSetGravity (world, 0, 0, -9.8);	//�d�͐ݒ�
	ground = dCreatePlane (space,0,0,1,0);//���ʂ̃W�I���g���쐬
	createBody();						//���{�b�g����

	// run simulation
	dsSimulationLoop (argc,argv,640,640,&fn);

	//��n��
	destroyBot ();
	dSpaceDestroy (space);
	dWorldDestroy (world);
	return 0;
}

