#include "stdafx.h"

#include "truss.h"

#include "../def.h"

using namespace ap::ship;
using namespace ap::mesh;


const Truss::Model Truss::single = {
		{
			&ap::textures::parts,
			&ap::regions::trusssingle
		}, /* strength */ 100, /* weight */ 100};

const Truss::Model Truss::uni = {
		{
			&ap::textures::parts,
			&ap::regions::trussuni
		}, 100, 100};

const Truss::Model Truss::duo = {
		{
			&ap::textures::parts,
			&ap::regions::trussduo
		}, 100, 100};

const Truss::Model Truss::opposite = {
		{
			&ap::textures::parts,
			&ap::regions::trussopposite
		}, 100, 100};

const Truss::Model Truss::tri = {
		{
			&ap::textures::parts,
			&ap::regions::trusstri
		}, 100, 100};

const Truss::Model Truss::quad = {
		{
			&ap::textures::parts,
			&ap::regions::trussquad
		}, 100, 100};




/* ###########################
   ## Getters & Setters
   ########################### */
Wall *ap::ship::Truss::gwall() {
	return wall;
}

//float ap::Ply::gy() {
//	return .0;
//}