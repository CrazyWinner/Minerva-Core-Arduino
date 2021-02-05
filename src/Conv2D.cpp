#include "Conv2D.h"

Conv2D::Conv2D(const INT_MNC& fsx, const INT_MNC& fsy, const INT_MNC& f_c, const INT_MNC& pd_x, const INT_MNC& pd_y, Activation::ActivationType act,  INT_MNC l_Id)
: Layer(act, l_Id)
{
	filter_size_X = fsx;
    filter_size_Y = fsy;
    filter_count = f_c;
    padding_X = pd_x;
    padding_Y = pd_y;
}

void Conv2D::init(const INT_MNC& inX, const INT_MNC& inY, const INT_MNC& inZ, Matrix3D *w, Matrix3D *b)
{
    i_X = inX;
    i_Y = inY;
    i_Z = inZ;
    weights = w;
    bias = b;
}


void Conv2D::getOutDimensions(INT_MNC &outX, INT_MNC &outY, INT_MNC &outZ) const
{
    outX = i_X - filter_size_X + 1 + (2 * padding_X);
    outY = i_Y - filter_size_Y + 1 + (2 * padding_Y);
    outZ = i_Z * filter_count;
}

float Conv2D::get_result(const Matrix3D &in, const INT_MNC& x1,  const INT_MNC& y1,  const INT_MNC& z, Layer **layers)
{
	INT_MNC outX, outY, outZ;
    getOutDimensions(outX, outY, outZ);
	/*
	if (isCacheEnabled() && cached)
	{
		return cache[p_id];
	}
	*/
	/*
	
	Ok, this was harder than i imagined
	i don't even know if it works or not
	
	*/
	float a = 0;
	INT_MNC which_filter = z % filter_count;
	INT_MNC z1 = z / filter_count;
    INT_MNC_SIGNED x = (INT_MNC_SIGNED)x1 + (((INT_MNC_SIGNED)i_X - (INT_MNC_SIGNED)outX) / 2);
	INT_MNC_SIGNED y = (INT_MNC_SIGNED)y1 + (((INT_MNC_SIGNED)i_Y - (INT_MNC_SIGNED)outY) / 2);
	for(INT_MNC_SIGNED dy = 0; dy < filter_size_Y; dy++){
		 for(INT_MNC_SIGNED dx = 0; dx < filter_size_X; dx++){		 
		    if ((y + dy - (filter_size_Y / 2) < 0 || y + dy - (filter_size_Y / 2) >= i_Y || x + dx - (filter_size_X / 2) < 0 || x + dx - (filter_size_X / 2) >= i_X)) continue;
				float b = layerId == 0 ? in.at(x + dx - (filter_size_X / 2), y + dy - (filter_size_Y / 2), z1) : layers[layerId - 1]->get_result(in, x + dx - (filter_size_X / 2), y + dy - (filter_size_Y / 2), z1, layers);
		     	a += b * weights->at(dx, dy, which_filter);
				
				
	}
	}
    
    /*
	
	
	
     THIS IS NOT EFFICIENT AT ALL
	 TODO: OPTIMIZE IT
	
	
	
	*/
	
	
	
	a += bias->at(0, which_filter, 0);
	Activation::activate(a, activationType);
/*
	if (isCacheEnabled())
	{
		cache[p_id] = a;
		if (p_id == outX * outY * outZ - 1)
	    cached = true;	
	}
	
	*/
	

	return a;
}
